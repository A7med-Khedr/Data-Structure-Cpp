#ifndef _DOUBLE_LINKED_LIST_H
#define _DOUBLE_LINKED_LIST_H
#include <iostream>
using namespace std;

template <typename T> // To Create T Data Type
// And Create List With Any Data Type But The Same List Contain The Same Data Type
class Double_Linked_List
{
	class Node
    {
    public:
        T data;     // Data Initial By User With T Data Type
        Node *next; // Pointer To Reference Next Node
        Node *prev; // Pointer To Reference Pervious Node

        Node(T data) : data(data), next(nullptr), prev(nullptr) {} // Constructor To Assign Value In Function For Data In Node
    };

private:
    Node *head = nullptr; // Head pointer To Reference Always In First Element In Double Linked List
    Node *tail = nullptr; // Tail pointer To Reference Always In Last Element In Double Linked List
    // ==========================

public:
	bool IS_EMPTY(); // Check List Empty Or No We Need It In Print Function
	void INSERT_NODE_AT_BEGINNING(T value); // Function To Add Element In First
	void INSERT_NODE_AT_END(T value); // Function To Add Data In Last
	void INSERT_NODE_AT_POSITION(T value, int pos); // Function To INsert Node In Any Place In Double Linked List
	void REMOVE_NODE(T value); // Function To Remove Node
	void PRINT_LINKED_LIST(); // Method To Print Linked List
	int GET_LENGTH(); // Function To Get Length Of List
};

#include "Double_Linked_List.cpp"

#endif
