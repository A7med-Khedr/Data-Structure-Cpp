// stack => LIFO ( Last In First Out )
#ifndef _STACK_CPP // any name as you like ( help compiler to provide include this file )
#define _STACK_CPP // and defined it
#include "./stack.h" // and incluse header file for stack to implement stack operations
#include <iostream>
using namespace std;

template <typename T> // template for generic data type
Stack<T>::Stack() : top(nullptr), size(0) {} // constructor to initialize stack with empty stack

template <typename T>
Stack<T>::Stack(const Stack<T>& other) : top(nullptr), size(0) {
    if (other.top == nullptr) return;

    Node* current = other.top;
    Stack<T> temp;

    while (current != nullptr) {
        temp.Push(current->data);
        current = current->next;
    }

    while (!temp.IsEmpty()) {
        this->Push(temp.Pop());
    }
}

template <typename T> // template for generic data type
Stack<T>::~Stack() // and destructor to free memory when stack is destroyed
{ // when we call pop function we call destructor to free memory
    while (!IsEmpty())
    {
        Pop();
    }
}

template <typename T>
bool Stack<T>::IsEmpty() const
{
    return top == nullptr; // check if stack is empty or not
}

template <typename T> // template for generic data type
void Stack<T>::Push(const T &value)
{
    Node *newNode = new Node(value); // create new node and assign value to it
    newNode->next = top; // next of new node we assign top of stack
    top = newNode; // and make new node as top of stack
    size++; // and increment size plus 1
}

template <typename T>
T Stack<T>::Pop()
{
    if (IsEmpty()) // check when we call it stack is empty or not
    {
        throw std::out_of_range("Stack Is Empty"); // if empty we call this exception
    }
    Node *temp = top; // and store top in temp variable
    T data = top->data; // store data we deleted in data variable
    top = top->next; // and move top one step forward
    delete temp; // delete temp node
    size--; // and decrement size by 1
    return data; // return data we deleted
}

template <typename T>
void Stack<T>::PrintStack() const
{
    if (IsEmpty()) // check if stack is empty or not
    {
        cout << "Stack Is Empty\n"; // if empty print this message
        return;
    }

    Node *current = top; // if not empty we create current in top to loop in stack
    cout << "Stack Element:\n";
    while (current != nullptr)
    {
        cout << current->data << "\n"; // and print all data
        current = current->next;
    }
}

template <typename T>
T Stack<T>::Top() const
{
    if (IsEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return top->data;
}

template <typename T>
int Stack<T>::GetLength() const
{
    return size; // return size of stack
}

#endif
