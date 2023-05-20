#ifndef DATASTRUCTURE_ARRAYQUEUE_H
#define DATASTRUCTURE_ARRAYQUEUE_H

#include "Queue.h"
#include "Array.h"

template<typename T>
class ArrayQueue : public Queue<T> {
private:
    Array<T> array;
public:
    ArrayQueue(int capacity) : array(capacity) {}

    ArrayQueue() : array() {}

    bool isEmpty() override {
        return array.isEmpty();
    }

    int getSize() override {
        return array.getSize();
    }

    T getFront() override {
        return array.getFirst();
    }

    void enqueue(T e) override {
        array.addLast(e);
    }

    T dequeue() override {
        return array.removeFirst();
    }

    template<typename U>
    friend std::ostream &operator<<(std::ostream &output, ArrayQueue<U> &arrayQueue) {
        output << "front [";
        for (int i = 0; i < arrayQueue.array.getSize(); ++i) {
            output << arrayQueue.array.get(i);
            if (i != arrayQueue.getSize() - 1)
                output << " ";
        }
        output << "] tail\n";
        return output;

    }
};

#endif //DATASTRUCTURE_ARRAYQUEUE_H
