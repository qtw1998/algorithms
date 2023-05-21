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

//    LoopQueue(const LoopQueue& other) {
//        capacity = other.capacity;
//        size = other.size;
//        front = other.front;
//        tail = other.tail;
//        data = new T[capacity];
//        for (int i = 0; i < size; ++i) {
//            data[i] = other.data[(other.front + i) % capacity];
//        }
//    }

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
    friend std::ostream &operator<<(std::ostream &output, LoopQueue<U> &loopQueue) {
        output << "Loop Queue, capacity: " << loopQueue.getCapacity() << " front [";
        for (int i = loopQueue.front; i != loopQueue.tail; i = (i + 1) % loopQueue.capacity) {
            output << loopQueue.data[i];
            if ((i + 1) % loopQueue.capacity != loopQueue.tail)
                output << " ";
        }
        output << "] tail \n";
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
        T *newData = new T[newCapacity + 1];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[(front + i) % capacity];
        }

        delete[] data;
        data = newData;
        capacity = newCapacity + 1;
        front = 0;
        tail = size;
    }
};

#endif //DATASTRUCTURE_LOOPQUEUE_H
