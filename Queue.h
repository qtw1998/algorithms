#ifndef DATASTRUCTURE_QUEUE_H
#define DATASTRUCTURE_QUEUE_H

template<typename T>
class Queue {
    virtual void enqueue(T e) = 0;

    virtual T dequeue() = 0;

    virtual T getFront() = 0;

    virtual int getSize() = 0;

    virtual bool isEmpty() = 0;
};

#endif //DATASTRUCTURE_QUEUE_H
