#include <iostream>
#include <chrono>
#include <random>
#include "Array.h"
#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "LoopQueue.h"

template<typename T>
double testQueue(Queue<T> &queue, int opCount) {
    auto startTime = std::chrono::high_resolution_clock::now();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, std::numeric_limits<int>::max());

    for (int i = 0; i < opCount; ++i)
        queue.enqueue(dis(gen));
    for (int i = 0; i < opCount; ++i)
        queue.dequeue();


    auto endTime = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = endTime - startTime;
    return elapsed.count();
}

int main() {

    int opCount = 100000;

    ArrayQueue<int> arrayQueue;
    double time2 = testQueue(arrayQueue, opCount);
    std::cout << "ArrayQueue time: " << time2 << std::endl;

    LoopQueue<int> loopQueue;
    double time1 = testQueue(loopQueue, opCount);
    std::cout << "LoopQueue time: " << time1 << std::endl;

    return 0;
}
