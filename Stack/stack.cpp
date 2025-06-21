#ifndef STACK_CPP // any name as you like ( help compiler to provide include this file )
#define STACK_CPP // and defined it
#include "./stack.h" // and incluse header file for stack to implement stack operations
#include <iostream>
using namespace std;

template <typename T> // template for generic data type
Stack<T>::Stack() : top(nullptr), size(0) {} // constructor to initialize stack with empty stack

template <typename T> // template for generic data type
Stack<T>::~Stack() // and destructor to free memory when stack is destroyed
{ // when we call pop function we call destructor to free memory
    while (!isEmpty())
    {
        pop();
    }
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
T Stack<T>::pop()
{
    if (isEmpty()) // check when we call it stack is empty or not
    {
        throw std::out_of_range("Stack Is Empty"); // if empty we call this exception
    }
    T data = top->data; // store data we deleted in data variable
    Node *temp = top; // and store top in temp variable
    top = top->next; // and move top one step forward
    delete temp; // delete temp node
    size--; // and decrement size by 1
    return data; // return data we deleted
}

template <typename T>
bool Stack<T>::isEmpty() const
{
    return top == nullptr; // check if stack is empty or not
}

template <typename T>
void Stack<T>::Display() const
{
    if (isEmpty()) // check if stack is empty or not
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
T Stack<T>::isTop() const
{
    if (isEmpty()) { // check if stack is empty or not
        cout << "Stack Is Empty\n"; // if empty print this message
    }
    else {
        cout << "Top Element: " << top->data << "\n"; // if not we print top element
    }
    return top->data;
}

template <typename T>
int Stack<T>::Get_Size() const
{
    return size; // return size of stack
}

#endif
