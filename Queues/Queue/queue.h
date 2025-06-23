#ifndef _QUEUE_H
#define _QUEUE_H

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
	void PrintQueue(); // method to print all elements in queue
	int GetLength(); // method to get the length of queue
    T Front(); // to get first element in queue
    T Back(); // to get last element in queue
    bool Contains(T value); // to search for specific element in queue
    void Reverse(); //  method to reverse the queue
    void Clear(); // method to clear the queue
};

#include "queue.tpp"

#endif