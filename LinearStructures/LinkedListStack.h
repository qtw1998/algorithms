//
// Created by qtw1998 on 23-5-26.
//

#ifndef DATASTRUCTURE_LINKEDLISTSTACK_H
#define DATASTRUCTURE_LINKEDLISTSTACK_H

#include "LinkedList.h"
#include "Stack.h"

template<typename T>
class LinkedListStack : public Stack<T> {
private:
    LinkedList<T> list;
public:
    int getSize() override {
        return list.getSize();
    }

    bool isEmpty() override {
        return list.isEmtpy();
    }

    void push(T e) override {
        list.addFirst(e);
    }

    T pop() override {
        return list.removeFirst();
    }

    T peek() override {
        return list.getFirst();
    }

    friend std::ostream &operator<<(std::ostream &output, const LinkedListStack &linkedListStack) {
        output << linkedListStack.list;
        return output;
    }
};

#endif //DATASTRUCTURE_LINKEDLISTSTACK_H
