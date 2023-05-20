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

    std::cout << loopQueue.getCapacity();

    return 0;
}
