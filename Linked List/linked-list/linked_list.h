#ifndef LINKED_LIST_H // any name as you like ( help compiler to provide include this file )
#define LINKED_LIST_H // and defined it

// #pragma once // can we use this statement if we do'nt want to use first defined
// but it not recommended to use it in header file because it not supported in all compiler

#include <stdexcept> // library in cpp to throw exception
using namespace std;

template <typename T> // allow me to make linked list with any type of data
class Linked_List // define class for a T data type
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
    Node *head = nullptr; // Head pointer To Reference Always In First Element In Linked List
    Node *tail = nullptr; // Tail Pointer To Reference Always In Last Element In Linked List
    
    bool isEmpty() const;  // Check List Empty Or No We Need It In Print Function

public:
	Linked_List();  // constructor to initialize linked list
	
    void insertNodeAtBeginning(T value); // method to insert node in first for linked list
    void insertNodeAtEnd(T value); // method to insert node in last for linked list
    void insertAtPosition(T value, int pos); // method to insert node for any place in linked list
    void removeNode(T value); // to remove node from any place for linked list
    void printList(); // to display elements for linked list
    int getLength(); // to get length of linked list
    T middleElement(); // to get middle element of linked list
};

#include "linked_list.cpp" // when we use template data type we need to incluse this file to compile it here

#endif // end of LINKED_LIST_H
