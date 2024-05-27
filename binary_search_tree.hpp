#include "bstree.h"

using namespace cocobolo;


template <typename T>
void BinarySearchTree<T>::_insert(const_reference value, node_pointer& root, node_pointer p)
{
	if (root == nullptr)
	{
		root = new Node<T>{value, p};
		return;
	}

	else if (root->m_data < value)
		this->_insert(value, root->right, root);

	else if (root->m_data > value)
		this->_insert(value, root->left, root);
}

// template <typename T>
// void BinarySearchTree<T>::_remove(node_pointer root) noexcept
// {
// 	Tree<T>::_remove(root);
// }


// template <typename T>
// typename BinarySearchTree<T>::const_node_pointer BinarySearchTree<T>::_find(const_reference value, node_pointer root) const noexcept
// {
// 	return Tree<T>::_find(value, root);
// }
