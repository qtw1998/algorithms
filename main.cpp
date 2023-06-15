#include <iostream>
#include <chrono>
#include <random>
#include "Array.h"
#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "LoopQueue.h"
#include "LinkedList.h"
#include "LinkedListStack.h"
#include "LinkedListQueue.h"
#include "BST.h"

/**
 *  我使用了 std::chrono 库来计算时间，它可以提供纳秒级别的精确度。
    我使用了 std::random_device 和 std::mt19937 来创建随机数生成器，然后使用 std::uniform_int_distribution 来生成 [1, INT_MAX] 范围内的随机数。这比C++的 rand() 函数提供更好的随机性和更大的数值范围。
    std::stack<int>& stack 是函数的参数，这样我们就可以在函数外部创建堆栈，并在函数内部使用它。这与Java的行为相似，因为Java总是按引用传递对象。
    elapsed.count() 返回的时间是以秒为单位的。
 * @tparam T
 * @param queue
 * @param opCount
 * @return
 */
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
//    test queue
//    ArrayQueue time: 617.415
//    LoopQueue time: 0.0258986
//    int opCount = 1000000;
//
//    ArrayQueue<int> arrayQueue;
//    double time2 = testQueue(arrayQueue, opCount);
//    std::cout << "ArrayQueue time: " << time2 << std::endl;
//
//    LoopQueue<int> loopQueue;
//    double time1 = testQueue(loopQueue, opCount);
//    std::cout << "LoopQueue time: " << time1 << std::endl;
//
//    return 0;

    // test LinkedList
//    LinkedList<int> linkedList;
//
//    for (int i = 0; i < 10; ++i) {
//        linkedList.add(i, i);
//    }
//    std::cout << linkedList << std::endl;
//
//    linkedList.remove(2);
//    std::cout << linkedList << std::endl;
//
//    linkedList.removeElement(9);
//    std::cout << linkedList << std::endl;

    // test LinkedListStack
//    LinkedListStack<int> linkedListStack;
//    for (int i = 0; i < 10; ++i) {
//        linkedListStack.push(i);
//        std::cout << linkedListStack << std::endl;
//    }
    // test LinkedListQueue.h
//    LinkedListQueue<int> queue;
//    for (int i = 0; i < 10; i++) {
//        queue.enqueue(i);
//        std::cout << queue << std::endl;
//
//        if (i % 3 == 2) {
//            queue.dequeue();
//            std::cout << queue << std::endl;
//        }
//    }
    // test Binary Search Tree
//    BST<int> bst;
//    int nums[] = {5, 3, 6, 8, 4, 2, 1};
//    for (int e: nums) {
//        bst.add(e);
//    }
//
//    bst.preOrder();
//    std::cout << bst << std::endl;
//    std::cout << bst.contains(4);
//    std::cout << std::endl;
//    bst.levelOrder();
//    std::cout << bst.minimum() << std::endl;
//    std::cout << bst.maximum();

    // test BST removeMin and removeMax
    BST<int> bst;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, 10000);

    int n = 1000;
    for (int i = 0; i < n; ++i)
        bst.add(dist(mt));

    std::vector<int> nums;
    while (!bst.isEmpty())
        nums.push_back(bst.removeMin());

    for (int i = 0; i < nums.size(); ++i)
        std::cout << nums[i] << " ";

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i - 1] > nums[i])
            throw std::runtime_error("Error!");
    }
    std::cout << std::endl;
    std::cout << "removeMin test completed." << std::endl;

    nums.clear(); // remove all elements from the vector

    return 0;
}
