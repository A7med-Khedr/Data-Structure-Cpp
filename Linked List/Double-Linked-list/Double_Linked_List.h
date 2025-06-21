#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H
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
	bool isEmpty(); // Check List Empty Or No We Need It In Print Function
	void Insert_Node_At_Beginning(T value); // Function To Add Element In First
	void Insert_Node_At_End(T value); // Function To Add Data In Last
	void Insert_At_Position(T value, int pos); // Function To INsert Node In Any Place In Double Linked List
	void Remove_Node(T value); // Function To Remove Node
	void Print_List(); // Method To Print Linked List
	int Get_Length(); // Function To Get Length Of List
};

#include "Double_Linked_List.cpp"

#endif
