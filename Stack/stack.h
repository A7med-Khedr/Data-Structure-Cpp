#ifndef _STACK_H // any name as you like ( help compiler to provide include this file )
#define _STACK_H // and defined it

// #pragma once // can we use this statement if we do'nt want to use first defined
// but it not recommended to use it in header file because it not supported in all compiler

#include <stdexcept> // library in cpp to throw exception
#include <iostream>
using namespace std;

template <typename T> // allow me to make stack with any type of data
class Stack // define class for a T data type
{
public:
    class Node // and defied node class
    {
    public:
        T data; // and this class have to element data and next
        Node *next; // and next is pointer to next node

        Node(const T &value) : data(value), next(nullptr) {} // constructor to defined initial data in node
    };

private:
    Node *top; // in stack have to a top node to get first node from stack
    int size; // and return size in stack

public:
    Stack(); // constructor to initialize stack
    ~Stack(); // destructor to free memory in stack

    void Push(const T &value); // push function in stack to push element is top of stack
    T Pop(); // and pop function to remove element from top of stack
    bool IsEmpty() const; // return boolean value to check if stack is empty or not
    void PrintStack() const; // to print stack
    T IsTop() const; // to get top element in stack
    int GetLength() const; // to get size of stack
};

#include "stack.cpp" // this line to include stack.cpp file because we define template data type in stack.cpp file

#endif // end of STACK_H
