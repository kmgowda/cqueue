//
// Created by kmg on 26/05/24.
//

#ifndef CQUEUE_QUEUEINTERFACE_H
#define CQUEUE_QUEUEINTERFACE_H
#include <cstdlib>
#include <mutex>
#include <queue>
#include <atomic>

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
            queue_.push(t);
            return true;
        }

        bool poll(T& t) override {
            std::unique_lock<std::mutex> lock(mutex_);
            t = queue_.front();
            queue_.pop();
            return true;
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
        }

        ~LinkedAtomicQueue() {
            delete firstNode_p_;
        }

        void clear() override {
            Node* tail = tail_p_.load();
            std::atomic_exchange(&tail_p_, tail);
           // Node* head = std::atomic_exchange(&head_p_, firstNode_p_);
            Node* head = head_p_.exchange(firstNode_p_);
            Node* cur = nullptr;
            while (head != nullptr) {
                cur = head;
                head = head->next;
                delete cur;
            }
        }

        bool add(T&& t) override {
            struct Node* tmp = new Node(std::move(t));
            struct Node* tail = tail_p_.exchange(tmp);
            tail->next.store(tmp);
            return true;
        }

        bool poll(T& t) override {
            struct Node* pHead = head_p_.exchange(nullptr);
            if (pHead == nullptr) {
                return false;
            }
            struct Node* cur = pHead->next.exchange(nullptr);
            if (cur == nullptr) {
                return false;
            }
            head_p_.store(cur);
            t = cur->item;
            if (pHead != firstNode_p_) {
                delete pHead;
            }
            return true;
        }

    };



} // cqueue

#endif //CQUEUE_QUEUEINTERFACE_H
