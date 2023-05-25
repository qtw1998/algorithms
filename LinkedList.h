//
// Created by qtw1998 on 23-5-24.
//

#ifndef DATASTRUCTURE_LINKEDLIST_H
#define DATASTRUCTURE_LINKEDLIST_H

#include <iostream>

template<typename T>
class LinkedList {
private:
    struct Node {
        T e;
        Node *next;

        Node(T e, Node *next) : e(e), next(nullptr) {}

        Node(T e) : e(e), next(nullptr) {}

        Node() : e(T()), next(nullptr) {}
    };

    Node *dummyHead;
    int size;
public:
    LinkedList() {
        dummyHead = new Node();
        size = 0;
    }

    ~LinkedList() {
        //TODO: 完成
        delete dummyHead;
    }

    int getSize() {
        return size;
    }

    bool isEmtpy() {
        return size == 0;
    }

    void add(int pos, T e) {
        if (pos < 0 || pos > size)
            throw std::invalid_argument("Add failed. Illegal index.");

        Node *prev = dummyHead;
        for (int i = 0; i < pos; ++i)
            prev = prev->next;
        prev->next = new Node(e, prev->next);
        ++size;
    }

    void addFirst(T e) {
        add(0, e);
    }

    void addLast(T e) {
        add(size, e);
    }

    T remove(int pos) {
        if (pos < 0 || pos >= size)
            throw std::invalid_argument("Remove failed. Illegal index.");

        Node *prev = dummyHead;
        for (int i = 0; i < pos - 1; ++i)
            prev = prev->next;

        Node *retNode = prev->next;
        prev->next = retNode->next;
        T ret = retNode->e;
        delete retNode;
        --size;
        return ret;
    }

    T removeFirst() {
        return remove(0);
    }

    T removeLast() {
        return remove(size - 1);
    }

    T get(int pos) {
        if (pos < 0 || pos >= size)
            throw std::invalid_argument("Get failed. Illegal index.");

        Node *curNode = dummyHead->next;
        for (int i = 0; i < pos; ++i)
            curNode = curNode->next;

        return curNode->e;
    }

    T getFist() {
        return get(0);
    }

    T getLast() {
        return get(size - 1);
    }

    void set(int pos, T e) {
        if (pos < 0 || pos >= size)
            throw std::invalid_argument("Set failed. Illegal index.");

        Node *curNode = dummyHead->next;
        for (int i = 0; i < pos; ++i)
            curNode = curNode->next;

        curNode->e = e;
    }

    bool contains(T e) {
        Node *curNode = dummyHead->next;
        while (curNode != nullptr) {
            if (curNode->e == e)
                return true;
            curNode = curNode->next;
        }
        return false;
    }

    void removeElement(T e) {
        // 效率较低 在每次删除时都重新扫描链表
//        Node *curNode = dummyHead->next;
//        for (int i = 0; i < size; ++i) {
//            if (curNode->e == e)
//                remove(i);
//        }
        Node *prev = dummyHead;
        while (prev->next != nullptr) {
            if (prev->next->e == e)
                break;
            prev = prev->next;
        }

        if (prev->next != nullptr) {
            Node *delNode = prev->next;
            prev->next = delNode->next;
            delete delNode;
            --size;
        }
    }

    template<typename U>
    friend std::ostream &operator<<(std::ostream &output, const LinkedList<U> &linkedList) {
        Node *curNode = linkedList.dummyHead->next;

        while (curNode != nullptr) {
            output << curNode->e << "->";
            curNode = curNode->next;
        }
        output << "NULL";
        return output;
    }
};

#endif //DATASTRUCTURE_LINKEDLIST_H
