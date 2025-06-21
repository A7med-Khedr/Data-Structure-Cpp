#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue
{
public:
    class Node
    { // Create Node Class
    public:
        T data;     // Create Data Input From User
        Node *next; // And Create Next POinter Tp Refer Nullptr If User Not Change This
        Node(const T &value) : data(value), next(nullptr) {}
        // Constructor To Assign value To Data From User And Assign Next Nullptr
    };

private:
    Node *head = nullptr; // Head Pointer Always Reference In First Element In Queue
    Node *tail = nullptr; // Tail Pointer Always Reference In Last Element In Queue
    int count = 0; // to get length for queue
	
public:
	bool IsEmpty();
	void EnQueue(T value); // method to add element in queue
	T DeQueue(); // method to remove element from queue
	void Print(); // method to print all elements in queue
	int GetLength(); // method to get the length of queue

};

#include "Queue.cpp"

#endif