#ifndef _TREE_TPP
#define _TREE_TPP
#include "tree.h"

template <typename T>
void Tree<T>::Insert(T value)
{
	Node *newNode = new Node(value); //create new node
	if (root == nullptr) // if root is null tree will be empty
	{
		root = newNode; // so we will insert new node as root
		return;
	}

	Node *current = root; // if tree is not empty we will start from root
	while (current != nullptr)
	{
		if (value < current->data) { // if value is less than current 
			if (current->left == nullptr) { // we check if left child is null
				current->left = newNode; // if null we insert node in left
				return;
			}
			current = current->left; // else we move to next left child

		} else if (value > current->data) { // if value is greater than current
			if (current->right == nullptr) { /// we check if right child is null
				current->right = newNode; // if null we insert node in right
				return;
			}
			current = current->right; // else we move to next right child

		} else {
			delete newNode; // and if current is equal to value we delete node and return
			return;
		}
	}
}

template <typename T>
bool Tree<T>::searchNode(const T& value) const
{
	Node *current = root; // create node to loop through tree
	while(current != nullptr) // if tree not empty
	{
		if (current->data == value) { // check if value is equal to current node
			return true; // if true return true
		}
		else if (current->data > value) { // if value is less than current node
			current = current->left; // move to left child
		} else { // if value is greater than current node
			current = current->right; // move to right child
		}
	}
	return false; // if value not found return false
}

#endif
