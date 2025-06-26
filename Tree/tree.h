#ifndef  TREE_H // unique identifier for this file
#define TREE_H // to provide redefine file when compile time

/* 
               10
             /    \
           5       15
         /  \     /  \
        2    8   12   20
*/

template <typename T>
class Tree
{

public:
	class Node // implement node class
	{
		public:
		T data; // to store data
		Node* left; // pointer refer to left child for node
		Node* right; // pointer refer to right child for node

		// define constructor to initialize node
		Node(T value): data(value), left(nullptr), right(nullptr) {}
	};

private:
	Node *root = nullptr;

public:
	void Insert(T value); // method to insert node for tree
	bool searchNode(const T& value) const; // method to search node in tree
};

#include "tree.tpp"

#endif // TREE_H // end of unique identifier
