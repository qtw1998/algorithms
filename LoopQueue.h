#ifndef DATASTRUCTURE_LOOPQUEUE_H
#define DATASTRUCTURE_LOOPQUEUE_H

#include "Queue.h"

template<typename T>
class LoopQueue : public Queue<T> {
public:
    explicit LoopQueue(int _capacity = 10) {
        capacity = _capacity + 1;
        data = new T[capacity];
        front = tail = 0;
        size = 0;
    }

    ~LoopQueue() {
        delete[] data;
    }

    /**
     * \brief return the real capacity for elements
     */
    int getCapacity() {
        return capacity - 1;
    }

    bool isEmpty() override {
        return tail == front;
    }

    void enqueue(T e) override {
        if ((tail + 1) % capacity == front)
            resize(getCapacity() * 2);
        data[tail] = e;
        tail = (tail + 1) % capacity;
        ++size;
    }

    T dequeue() override {
        if (isEmpty())
            throw std::runtime_error("Queue is empty.");

        T res = data[front];
        front = (front + 1) % capacity;
        --size;
        if (size <= getCapacity() / 4 && getCapacity() / 2 != 0)
            resize(getCapacity() / 2);

        return res;
    }

    T getFront() override {
        if (isEmpty())
            throw std::runtime_error("Queue is empty.");
        return data[front];
    }

    int getSize() override {
        return size;
    }

    template<typename U>
    friend std::ostream &operator<<(std::ostream &output, LoopQueue<T> &loopQueue) {
        output << "front [";
        for (int i = loopQueue.front; i != loopQueue.tail; i = (i + 1) % loopQueue.capacity) {
            output << loopQueue.data[i];
            if (i != loopQueue.size - 1)
                output << " ";
        }
        output << "[ tail \n";
        return output;
    }

private:
    T *data;
    int front, tail;
    int size, capacity; // capacity for the array calculated in memory size

    /**
     * \brief resize the array
     * @param newCapacity real elements size
     */
    void resize(int newCapacity) {
        capacity = newCapacity + 1;
        T *newData = new T[newCapacity + 1];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[(front + i) % capacity];
        }

        delete[] data;
        data = newData;
        front = 0;
        tail = size;
    }
};

#endif //DATASTRUCTURE_LOOPQUEUE_H
