//Copyright 2021 William Chin
//Email: wchin1@sfsu.edu
//This file is apart of CSC340 -Assignment 3

#pragma once
#include <iostream>
#include "stackinterface.h"

#define SIZE 6
template<class ItemType>
class stack
{
    ItemType * arr;
    int top;
    int capacity;

public:
    stack(int size = SIZE);         // constructor
    ~stack();                       // destructor

    bool push(const ItemType&);
    bool pop();
    ItemType peek() const;
    bool isEmpty() const;
    bool isFull();

    int size();
};
using namespace std;
template<class ItemType>
stack<ItemType>::stack(int size) {
    arr = new ItemType[size];
    capacity = size;
    top = -1;
}

template<class ItemType>
stack<ItemType>::~stack() {
    delete[] arr;
}

template<class ItemType>
bool stack<ItemType>::push(const ItemType & x) {
    //overflow chek
    if (isFull()) {
        cout << "Stack is full, doubling size" << endl;
        ItemType* old_arr = arr;
        arr = new ItemType[2 * capacity];
        for (int i = 0; i < capacity; i++) {
            arr[i] = old_arr[i];
        }
        delete [] old_arr;
        capacity *= 2;

    }
    
    cout << "Pushing " << x << endl;
    arr[++top] = x;
    return true;
 }

template<class ItemType>
bool stack<ItemType>::pop() {
    //underflow check
    if (isEmpty()) {
        cout << "Underflow" << endl;
    }
    else {
        cout << "Popping " << peek() << endl;
        arr[top--];
    }
    return true;
}

template<class ItemType>
ItemType stack<ItemType>::peek() const {
    if (!isEmpty())
        return arr[top];
    else {
        ItemType temp{ ' ' };
        cout << "Empty" << endl;
        return temp;
    }
}

template<class ItemType>
int stack<ItemType>::size() {
    return top + 1;
}

template<class ItemType>
bool stack<ItemType>::isEmpty() const {
    return top == -1;
}

template<class ItemType>
bool stack<ItemType>::isFull() {
    if (top == capacity - 1) {
        return 1;
    }
    else
        return 0;
}
