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
    class LinkedBlockingQueue : public QueueInterface<T> {

    private:
        std::mutex mutex_;
        std::queue<T> queue_;

    public:
        ~LinkedBlockingQueue()  = default;

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
    template<typename T>
    class LinkedAtomicQueue : public QueueInterface<T> {

    private:
        template<typename X>
        struct Node {
            X item;
            std::atomic<struct Node<X>*> next;

            Node() {
               next = nullptr;
            }

            Node(X&& x) {
                item = x;
                next = nullptr;
            }
        };

        std::atomic<struct Node<T>*> head_;
        std::atomic<struct Node<T>*> tail_;
        const struct Node<T>* firstNode_;

    public:
        LinkedAtomicQueue() {
            firstNode_ = new Node<T>();
        }

        ~LinkedAtomicQueue() {
            delete firstNode_;
        }

        void clear() override {
           // struct Node<T>* tail = tail_.exchange(firstNode_);
            struct Node<T>* tail = std::atomic_exchange(&tail_, firstNode_);
            struct Node<T>* head = head_.exchange(firstNode_);
            struct Node<T>* cur = nullptr;
            while (head != nullptr) {
                cur = head;
                head = head->next;
                delete cur;
            }
        }

        bool add(T&& t) override {
            struct Node<T>* tmp = new Node<T>(std::move(t));
            struct Node<T>* tail = tail_.exchange(tmp);
            tail->next.store(tmp);
            return true;
        }

        bool poll(T& t) override {
            struct Node<T>* pHead = head_.exchange(nullptr);
            if (pHead == nullptr) {
                return false;
            }
            struct Node<T>* cur = pHead->next.exchange(nullptr);
            if (cur == nullptr) {
                return false;
            }
            head_.store(cur);
            t = cur->item;
            if (pHead != firstNode_) {
                delete pHead;
            }
            return true;
        }

    };

 */

} // cqueue

#endif //CQUEUE_QUEUEINTERFACE_H
