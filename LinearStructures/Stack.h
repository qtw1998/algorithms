//
// Created by qtw1998 on 23-4-8.
//

#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H

template<typename T>
class Stack {
public:
    virtual void push(T e) = 0;

    virtual T pop() = 0;

    virtual T peek() = 0;

    virtual int getSize() = 0;

    virtual bool isEmpty() = 0;


};

#endif //DATASTRUCTURE_STACK_H
