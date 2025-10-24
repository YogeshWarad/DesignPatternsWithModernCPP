#include "BoundedQueue.h"
#include <thread>
#include <vector>
#include <functional>
#include <chrono>
#include <random>

template<typename T>
void ProducerTask(BoundedQueue<T> &queue, T itemToPush, int numItems)
{
    for(int i = 0;  i < numItems; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        queue.produce(itemToPush);
    }
}

template<typename T>
void ConsumerTask(BoundedQueue<T> &queue, T /*unused*/, int numItems)
{
    for(int i = 0;  i < numItems; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        // consume one item (ignore the returned value here)
        queue.consume();
    }
}

int main() 
{
    BoundedQueue<int> queue(5);
    const int numItems = 10;

    const int producers = 2;
    const int consumers = 2;
    const int itemsPerProducer = 5;

    std::vector<std::thread> threads;

    for (int i = 0; i < producers; ++i)
        threads.emplace_back(ProducerTask<int>, std::ref(queue), i + 1, itemsPerProducer);

    for (int i = 0; i < consumers; ++i)
        threads.emplace_back(ConsumerTask<int>, std::ref(queue), i + 1, itemsPerProducer);


    for (auto& t : threads)
        t.join();

    return 0;
}