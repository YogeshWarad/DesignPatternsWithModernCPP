#include"BoundedQueue.h"
#include <queue>

template<typename T>
BoundedQueue<T>::BoundedQueue(size_t capacity) : capacity_(capacity) {}

template<typename T>
bool BoundedQueue<T>::isEmpty() const {
    return queue_.empty();
}

template<typename T>
bool BoundedQueue<T>::isFull() const {
    return queue_.size() >= capacity_;
}

template<typename T>
size_t BoundedQueue<T>::size() const {
    return queue_.size();
}

template<typename T>
void BoundedQueue<T>::produce(T item){
    std::lock_guard<std::mutex> lock(mutex_);
    not_full_.wait(lock, [this](){ return queue_.size() < capacity_;})
    queue_.push(item);
    lock.unlock();
    not_empty_.notify_one();
}

template<typename T>
T BoundedQueue<T>::consume()
{
    T ret;
    std::lock_guard<std::mutex> lock(mutex_);
    not_empty_.wait(lock, [this]){ return queue_.empty();}
    ret = queue_.front();
    lock.unlock();
    not_full.notify_one();
}