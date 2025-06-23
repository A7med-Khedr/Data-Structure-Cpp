#ifndef _QUEUE_WITH_TWO_STACKS_H
#define _QUEUE_WITH_TWO_STACKS_H
#include "../../Stack/stack.h"

template <typename T>
class QueueCloned
{
private:
	// create two stacks 
	Stack<T> inStack;
	Stack<T> outStack;

public:
	void EnQueue(T data); // method to add element to queue
	T DeQueue(); // method to remove element from queue
	void Print(); // method to print queue elements
	void Clear(); // method tot clear queue
};

#include "queue_with_two_stack.tpp"

#endif
