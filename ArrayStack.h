//
// Created by qtw1998 on 23-4-9.
//

#ifndef DATASTRUCTURE_ARRAYSTACK_H
#define DATASTRUCTURE_ARRAYSTACK_H

#include "Stack.h"
#include "Array.h"

template<typename T>
class ArrayStack : public Stack<T> {
private:
    Array<T> array;
public:
//    ArrayStack(int capacity) {
//        array = new Array<T>(capacity);
//    }
//
//    ArrayStack() {
//        array = new Array<T>();
//    }

    ArrayStack(int capacity) : array(capacity) {};

    ArrayStack() : array() {};

    int getSize() override {
        return array.getSize();
    }

    bool isEmpty() override {
        return array.isEmpty();
    }

    int getCapacity() {
        return array.getCapacity();
    }

    T peek() override {
        return array.getLast();
    }

    T pop() override {
        return array.removeLast();
    }

    void push(T e) override {
        array.addLast(e);
    }

    template<typename U>
    friend std::ostream &operator<<(std::ostream &output, ArrayStack<U> &arrayStack) {
//        output << "Stack Size: " << arrayStack.array.getSize() << ", Capacity: " << arrayStack.array.getCapacity() << "." << std::endl;
        output << "[";
        for (int i = 0; i < arrayStack.array.getSize(); ++i) {
            output << arrayStack.array.get(i);
            if (i != arrayStack.getSize() - 1)
                output << " ";
        }
        output << "] top\n";
        return output;
    }

};


#endif //DATASTRUCTURE_ARRAYSTACK_H
