//
// Created by qtw1998 on 23-3-23.
//

#ifndef DATASTRUCTURE_ARRAY_H
#define DATASTRUCTURE_ARRAY_H

#include <iostream>

template<typename T>
class Array {
public:
    Array(int capacity);

    Array();

    Array(const Array &obj);

    ~Array();

    int getSize();

    bool isEmpty();

    void add(int index, T e);

    void addLast(T e);

    void addFirst(T e);

    template<typename U>
    friend std::ostream &operator<<(std::ostream &output, const Array<U> &array);

    void printArray();

    T get(int index);

    void set(int index, T e);

    bool contains(T e);

    int find(T e);

    T remove(int index);

    T removeFirst();

    T removeLast();

    void removeElement(T e);

    int getCapacity();

    T getLast();

    T getFirst();

private:
    T *data;
    int size;
    int capacity;

    void resize(int newCapacity);
};

template<typename T>
T Array<T>::getFirst() {
    return get(0);
}

template<typename T>
T Array<T>::getLast() {
    return get(size - 1);
}

template<typename T>
int Array<T>::getCapacity() {
    return capacity;
}

template<typename T>
Array<T>::Array(const Array &obj) {
    size = obj.size;
    capacity = obj.capacity;
    data = new T[capacity];
    std::copy(obj.data, obj.data + size, data);
}

template<typename T>
Array<T>::~Array() {
    delete[] data;
}

template<typename T>
void Array<T>::resize(int newCapacity) {
    T *newData = new T[newCapacity];
    for (int i = 0; i < size; ++i)
        newData[i] = data[i];
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

template<typename T>
void Array<T>::removeElement(T e) {
    int index = find(e);
    if (index != -1)
        remove(index);
}

template<typename T>
T Array<T>::removeLast() {
    return remove(size - 1);
}

template<typename T>
T Array<T>::removeFirst() {
    return remove(0);
}

template<typename T>
T Array<T>::remove(int index) {
    if (index < 0 || index >= size)
        throw "Remove failed. Require index >= 0 and index < size";

    T res = data[index];
    for (int i = index + 1; i < size; ++i)
        data[i - 1] = data[i];
    --size;
    if (size <= capacity / 2 && capacity / 2 != 0)
        resize(capacity / 2);
    return res;
}

template<typename T>
int Array<T>::find(T e) {
    for (int i = 0; i < size; ++i) {
        if (data[i] == e)
            return i;
    }
    return -1;
}

template<typename T>
bool Array<T>::contains(T e) {
    for (int i = 0; i < size; ++i) {
        if (data[i] == e)
            return true;
    }
    return false;
}

template<typename T>
void Array<T>::set(int index, T e) {
    if (index < 0 || index >= size)
        throw "Set failed. Require index >= 0 and index < size";
    data[index] = e;
}

template<typename T>
T Array<T>::get(int index) {
    if (index < 0 || index >= size)
        throw "Get failed. Require index >= 0 and index < size.";
    return data[index];
}

template<typename U>
std::ostream &operator<<(std::ostream &output, const Array<U> &array) {
    output << "Array Size: " << array.size << ", Capacity: " << array.capacity << "." << std::endl;
    output << "[";
    for (int i = 0; i < array.size; ++i) {
        output << array.data[i];
        if (i != array.size - 1)
            output << " ";
    }
    output << "]\n";
    return output;
}


template<typename T>
void Array<T>::add(int index, T e) {
    if (index < 0 || index > size)
        throw "Add failed. Require index >= 0 and index <= size."; // continuously added

    if (size == capacity)
        resize(capacity * 2);

    for (int i = size - 1; i >= index; --i)
        data[i + 1] = data[i];

    data[index] = e;
    ++size;
}

template<typename T>
bool Array<T>::isEmpty() {
    return size == 0;
}

template<typename T>
int Array<T>::getSize() {
    return size;
}

template<typename T>
Array<T>::Array() : Array(10) {}

template<typename T>
Array<T>::Array(int capacity) {
    data = new T[capacity];
    size = 0;
    this->capacity = capacity;
}

template<typename T>
void Array<T>::addFirst(T e) {
    add(0, e);
}

template<typename T>
void Array<T>::addLast(T e) {
    add(size, e);
}

template<typename T>
void Array<T>::printArray() {
    std::cout << "Array size: " << size << ", capacity: " << capacity << std::endl;
    std::cout << "[";
    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << "]" << std::endl;
}

#endif //DATASTRUCTURE_ARRAY_H
