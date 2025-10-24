#pragma once

#include <cstddef>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <utility>

template<typename T>
class BoundedQueue 
{
public:
    explicit BoundedQueue(size_t capacity) : capacity_(capacity) {}

    bool isEmpty() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return queue_.empty();
    }

    bool isFull() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return queue_.size() >= capacity_;
    }

    size_t size() const {
        std::lock_guard<std::mutex> lock(mutex_);
        return queue_.size();
    }

    void produce(T item){
        std::unique_lock<std::mutex> lock(mutex_);
        not_full_.wait(lock, [this](){ return queue_.size() < capacity_; });
        queue_.push(std::move(item));
        lock.unlock();
        not_empty_.notify_one();
    }

    T consume(){
        std::unique_lock<std::mutex> lock(mutex_);
        not_empty_.wait(lock, [this](){ return !queue_.empty(); });
        T ret = std::move(queue_.front());
        queue_.pop();
        lock.unlock();
        not_full_.notify_one();
        return ret;
    }

private:
    mutable std::mutex mutex_;
    std::queue<T> queue_;
    size_t capacity_;
    std::condition_variable not_full_;
    std::condition_variable not_empty_;
};