//
// Created by qtw1998 on 23-6-16.
//

#ifndef DATASTRUCTURE_SET_H
#define DATASTRUCTURE_SET_H

template<typename T>
class Set {
public:
    virtual void add(T e) = 0;

    virtual bool contains(T e) = 0;

    virtual void remove(T e) = 0;

    virtual int getSize() = 0;

    virtual bool isEmpty() = 0;
};

#endif //DATASTRUCTURE_SET_H
