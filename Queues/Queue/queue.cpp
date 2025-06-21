// queue => FIFO ( First In First Out )
#ifndef _QUEUE_CPP
#define _QUEUE_CPP
#include <stdexcept> // Library In C++ Allow Me Print Massage As Error
#include "./Queue.h"

template <typename T>
bool Queue<T>::IsEmpty()
{
    return head == nullptr; // Line => Head == Nullptr ? True : False
}

template <typename T>
void Queue<T>::EnQueue (T value)
{
    Node *New_Node = new Node(value); // Create New Node And Assign Value To Data In Class
    if (tail == nullptr)
    {                    // If Queue Is Empty
        head = New_Node; // Assign head Pointer To New_Node And Tail Already Nullptr
    }
    else
    {                          // If There Many Element
        tail->next = New_Node; // Next Pointer Assign To New Node
    }
    tail = New_Node; // And Update tail Pointer To New Node Because Tail Refer Last Element
    count++;         // Increment Count Plus 1 To Get Final Length
}

template <typename T>
T Queue<T>::DeQueue()
{ 
    if (IsEmpty())
    {
        throw out_of_range("Queue Is Empty"); // Throw Massage Error ( Queue Is Empty )
    }
    else
    {
        T value = head->data; // Create Value With Any Data Type And Assign This In data Of Head
        head = head->next;    // And Update Head Pointer To Next Element
        if (head == nullptr)
        {                   // After Update Head If Refer Nullptr Mean Queue Became Empty
            tail = nullptr; // Assign tail Equal Nullptr Because Queue Became Empty
        }
        count--; // Decrement Count Minus 1 To Get Final length
        return value;
    }
}

template <typename T>
void Queue<T>::PrintQueue()
{
    if (IsEmpty())
    {                               // Check If Queue Is Empty Or No
        cout << "Queue Is Empty\n"; // If Empty Print This
    }
    else
    {                         // If Not Empty
        Node *current = head; // Create Current Pointer To Move In Queue
        while (current != nullptr)
        {                                  // Until Arrive Last Element
            cout << current->data << "\n"; // Print Element
            current = current->next;       // Increment loop
        }
    }
}

template <typename T>
int Queue<T>::GetLength()
{
    return count; // Return Final Count
}

template <typename T>
T Queue<T>::Front()
{
    if (IsEmpty()) // if Queue Is Empty
        throw std::out_of_range("Queue is empty"); // Throw Massage Error ( Queue Is Empty )
    return head->data; // if not empty Return First Element
}

template <typename T>
T Queue<T>::Back()
{
    if (IsEmpty()) // if Queue Is Empty
        throw std::out_of_range("Queue is empty"); // Throw Massage Error ( Queue Is Empty )
    return tail->data; // if not empty Return Last Element
}

template <typename T>
bool Queue<T>::Contains(T value)
{
    Node* current = head; // Create Current Pointer To Move In Queue
    while (current != nullptr) // Until Arrive Last Element
    {
        if (current->data == value) // Check If Current Element Is Equal To Value
            return true; // Return True If Found
        current = current->next; // Increment loop
    }
    return false; // Return False If Not Found
}

template <typename T>
void Queue<T>::Reverse()
{
    Node* prev = nullptr; // Create Previous Pointer
    Node* current = head; // Create Current Pointer To Move In Queue
    tail = (head == nullptr) ? nullptr : tail; // Set Tail To Null If Queue Is Empty

    while (current != nullptr)
    {
        Node* next = current->next; // Create Next Pointer To Move In Queue
        current->next = prev; // Reverse Link
        prev = current; // Move Previous Pointer
        current = next; // Move Current Pointer
    }

    head = prev; // Set Head To New First Element
}

template <typename T>
void Queue<T>::Clear()
{
    while (!IsEmpty()) // While Queue Is Not Empty
        DeQueue(); // Remove Elements
}

#endif
