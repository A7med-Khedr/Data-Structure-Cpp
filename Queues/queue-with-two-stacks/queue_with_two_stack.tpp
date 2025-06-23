#ifndef _QUEUE_WITH_TWO_STACKS_CPP
#define _QUEUE_WITH_TWO_STACKS_CPP
#include "queue_with_two_stack.h"

template <typename T>
void QueueCloned<T>::EnQueue(T data)
{ // enqueue method similar to push in stack
	inStack.Push(data);
}

/*
	but dequeue method is different
	because we need to reverse stack and print it
	inStack include first element we reverse it in outStack and pop first element
*/ 

template <typename T>
T QueueCloned<T>::DeQueue()
{
	if (outStack.IsEmpty()) // is outStack is empty we will reverse inStack
	{
		while (!inStack.IsEmpty())
		{
			outStack.Push(inStack.Top()); // push first element of inStack to outStack
			inStack.Pop(); // and change top of inStack when remove element
		}
	}

	if (inStack.IsEmpty() && outStack.IsEmpty()) // if inStack is empty we can't dequeue and print this
	{
		throw std::out_of_range("Queue is empty");
	}

	// if outStack is not empty we remove from this stack
	T valueRemoved = outStack.Top();
	outStack.Pop();
	return valueRemoved; // and return value when remove it
}

template <typename T>
void QueueCloned<T>::Print()
{
	if (!outStack.IsEmpty()) { // when outStack is not empty we print it because it include first elements
		outStack.PrintStack();
	}

	// if inStack is not empty we reverse it and print elements of inStack
	if (!inStack.IsEmpty()) {
		Stack<T> temp; // to reverse stack
		Stack<T> copy = inStack; // clone with inStack because don't need to change inStack

		while (!copy.IsEmpty()) { // reverse
			temp.Push(copy.Top());
			copy.Pop();
		}

		temp.PrintStack(); // and print elements in this stack
	}
}

template <typename T>
void QueueCloned<T>::Clear()
{
	while (!outStack.IsEmpty()) { // when outStack is not empty we remove all elements
		outStack.Pop();
	}

	while (!inStack.IsEmpty()) { // and when inStack is not empty we remove all elements
		inStack.Pop();
	}
}

#endif
