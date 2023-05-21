#include <iostream>
#include "Array.h"
#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "LoopQueue.h"

int main() {
//    Array<int> array;
//    for (int i = 0; i < 5; ++i) {
//        array.addLast(i);
//    }
//
//    std::cout << array;
//
//    for (int i = 5; i < 15; ++i)
//        array.addLast(i);
//
//    std::cout << array;
//
//    for (int i = 0; i < 7; ++i)
//        array.removeLast();
//
//    std::cout << array;

//    ArrayStack<int> arrayStack;
//    for (int i = 0; i < 5; ++i) {
//        arrayStack.push(i);
//        std::cout << arrayStack;
//    }
//    arrayStack.pop();
//    std::cout << arrayStack;

//    ArrayQueue<int> arrayQueue;
//    for (int i = 0; i < 5; ++i) {
//        arrayQueue.enqueue(i);
//        std::cout << arrayQueue;
//    }
//
//    arrayQueue.dequeue();
//    std::cout << arrayQueue;

    LoopQueue<int> loopQueue;

    for (int i = 0; i < 10; ++i) {
        loopQueue.enqueue(i);
        std::cout << loopQueue;
    }

    loopQueue.dequeue();
    loopQueue.dequeue();
    loopQueue.dequeue();
    loopQueue.dequeue();
    loopQueue.dequeue();
    loopQueue.dequeue();
    std::cout << loopQueue;

    for (int i = 11; i < 21; ++i) {
        loopQueue.enqueue(i);
        std::cout << loopQueue;
    }
//    loopQueue.dequeue();
//    loopQueue.dequeue();
//    loopQueue.dequeue();

    return 0;
}
