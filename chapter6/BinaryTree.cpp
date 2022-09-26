#include "BinaryTree.h"

template <typename elemType>
inline BinaryTree<elemType>::
BinaryTree() : _root( 0 )
{}

template <typename elemType>
inline BinaryTree<elemType>::BinaryTree(const BinaryTree &rhs) {
	 copy(_root, rhs._root); 
}

template <typename elemType>
inline BinaryTree<elemType>::~BinaryTree() { 
    clear(); 
}

template <typename elemType>
inline BinaryTree<elemType>& BinaryTree<elemType>::operator=(const BinaryTree &rhs) {
	if (this != &rhs) {
		clear();
		copy(_root, rhs._root);
	}
	return *this;
}