//
// Created by qtw1998 on 23-5-26.
//

#ifndef DATASTRUCTURE_LINKEDLISTQUEUE_H
#define DATASTRUCTURE_LINKEDLISTQUEUE_H

#include <iostream>
#include "Queue.h"

template<typename T>
class LinkedListQueue : public Queue<T> {
private:
    struct Node {
        T e;
        Node *next;

        Node(T e, Node *next) : e(e), next(next) {}

        Node(T e) : e(e), next(nullptr) {}

        Node() : e(T()), next(nullptr) {}
    };

    Node *head;
    Node *tail;
    int size;
public:
    LinkedListQueue() : head(nullptr), tail(nullptr), size(0) {}

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(T e) {
        if (tail == nullptr) {
            tail = new Node(e);
            head = tail;
        } else {
            tail->next = new Node(e);
            tail = tail->next;
            ++size;
        }
    }

    T dequeue() {
        if (isEmpty())
            throw std::invalid_argument("Cannot dequeue from an empty queue.");

        Node *retNode = head;
        head = head->next;

        if (head == nullptr)
            tail = nullptr;
        T retValue = retNode->e;
        delete retNode;
        --size;

        return retValue;
    }

    T getFront() {
        if (isEmpty())
            throw std::invalid_argument("Queue is empty.");
        return head->e;
    }

    template<typename U>
    friend std::ostream &operator<<(std::ostream &output, const LinkedListQueue<U> &linkedListQueue) {
        output << "Queue Front: ";

        Node *cur = linkedListQueue.head;
        while (cur != nullptr) {
            output << cur->e;
            if (cur->next != nullptr)
                output << " ";
            cur = cur->next;
        }
        output << " NULL tail";
        return output;
    }
};

#endif //DATASTRUCTURE_LINKEDLISTQUEUE_H
