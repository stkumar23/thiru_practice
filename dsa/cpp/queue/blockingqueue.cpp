// DSA - Blocking Queue
// Queue Operations: push, pop
//
// Compile with -std=c++11
//
// Author: Thiru

#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

template <typename E>
class blocking_queue {

public:
    blocking_queue(int size) : msize(size) {
    }

    // Push waits for element removal in case the max size is reached
    void push(E e) {
        std::unique_lock<std::mutex> lock(mmtx);
        mcv.wait(lock, [&](){ return mqueue.size() < msize; });
        mqueue.emplace(e);
        lock.unlock();
        mcv.notify_one();
    }

    // pop waits for element push in case the queue is empty
    void pop() {
        std::unique_lock<std::mutex> lock(mmtx);
        mcv.wait(lock, [&](){ return !mqueue.empty(); });
        mqueue.pop();
        lock.unlock();
        mcv.notify_one();
    }

    E front() {
        std::lock_guard<std::mutex> lock(mmtx);
        return mqueue.front();
    }

    int getsize() {
        std::lock_guard<std::mutex> lock(mmtx);
        return mqueue.size();
    }

private:
    int msize;
    std::mutex mmtx;
    std::condition_variable mcv;
    std::queue<E> mqueue;
};

int main() {
    // max size is set to 5
    blocking_queue<int> bq(5);

    std::thread t1([&](){
        for (int i=0; i<10; i++) {
            bq.push(i);
            std::cout<<"thread push top element "<<bq.front()<<std::endl;
        }
    });

    std::thread t2([&](){
        for (int i=0; i<10; i++) {
            bq.pop();
            std::cout<<"thread pop top element "<<bq.front()<<std::endl;
        }
    });

    t1.join();
    t2.join();

    return 0;
}