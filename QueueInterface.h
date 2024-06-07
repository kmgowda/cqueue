//
// Created by kmg on 26/05/24.
//

#ifndef CQUEUE_QUEUEINTERFACE_H
#define CQUEUE_QUEUEINTERFACE_H
#include <cstdlib>
#include <mutex>
#include <queue>
#include <atomic>
#include <boost/lockfree/queue.hpp>

namespace cqueue {

    template<typename  T>
    class QueueInterface {

    public:

        virtual ~QueueInterface() = default;

        virtual bool add(T&& t) = 0;

        virtual bool poll(T& t) = 0;

        virtual void clear() = 0;

    };

    template<typename T>
    class NonBlockingQueue : public QueueInterface<T> {

    private:
        std::mutex mutex_;
        std::queue<T> queue_;

    public:
        ~NonBlockingQueue()  = default;

        void clear() override {
            std::unique_lock<std::mutex> lock(mutex_);
            while (queue_.empty()) {
                queue_.pop();
            }
        }

        bool add(T&& t) override {
            std::unique_lock<std::mutex> lock(mutex_);
            queue_.push(std::move(t));
            return true;
        }

        bool poll(T& t) override {
            std::unique_lock<std::mutex> lock(mutex_);
            t = std::move(queue_.front());
            queue_.pop();
            return true;
        }

    };

    template<typename T>
    class BoostLockFreeQueue : public QueueInterface<T> {

    private:
        std::shared_ptr<boost::lockfree::queue<T>> queue_p;

    public:
        BoostLockFreeQueue(){
            queue_p = std::make_shared<boost::lockfree::queue<T>>(1024);
        }
        ~BoostLockFreeQueue()  = default;

        void clear() override {
            T t;
            while (queue_p->empty()) {
                queue_p->pop(t);
            }
        }

        bool add(T&& t) override {
            return queue_p->push(t);
        }

        bool poll(T& t) override {
           return queue_p->pop(t);
        }

    };



/*
 *  The linked atomic queue does not work with struct pointer due to copyable restrictions
 */

template<typename T>
class LinkedAtomicQueue : public QueueInterface<T> {

    private:
        struct Node {
            T item;
            std::atomic<Node*> next;

            Node() {
               next = nullptr;
            }

            Node(T&& tData) {
                item = tData;
                next = nullptr;
            }
        };

        std::atomic<Node*> head_p_;
        std::atomic<Node*> tail_p_;
        Node* firstNode_p_;

    public:
        LinkedAtomicQueue() {
            firstNode_p_ = new Node();
            tail_p_.store(firstNode_p_);
            head_p_.store(firstNode_p_);
        }

        ~LinkedAtomicQueue() {
            delete firstNode_p_;
        }

        void clear() override {
            Node* head = head_p_.exchange(firstNode_p_);
            tail_p_.store(firstNode_p_);
            Node* cur = nullptr;
            while (head != nullptr) {
                cur = head;
                head = head->next;
                delete cur;
            }
        }

        bool add(T&& t) override {
            Node* tmp = new Node(std::move(t));
            Node* tail = tail_p_.exchange(tmp);
            tail->next.store(tmp);
            return true;
        }

        bool poll(T& t) override {
            Node* pHead = head_p_.load();
            Node* nxt = pHead->next.load();
            while(nxt != nullptr && !head_p_.compare_exchange_weak(pHead, nxt))  {
                pHead = head_p_.load();
                nxt = pHead->next.load();
            }
            if(nxt == nullptr) {
                return false;
            }
            if(pHead != firstNode_p_) {
                delete pHead;
            }
            t = std::move(nxt->item);
            return true;
        }

    };



} // cqueue

#endif //CQUEUE_QUEUEINTERFACE_H
