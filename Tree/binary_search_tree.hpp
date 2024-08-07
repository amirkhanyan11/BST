#include "bstree.h"

using namespace cocobolo;

template <typename T, typename Compare>
void BinarySearchTree<T, Compare>::_insert(const_reference value, node_pointer& root, node_pointer p)
{
	if (root == nullptr)
	{
		root = new node_type{value, p};
		return;
	}

	else if (this->comp(root->val, value))
		this->_insert(value, root->right, root);

	else if (this->comp(value, root->val))
		this->_insert(value, root->left, root);
}

template <typename T, typename Compare>
BinarySearchTree<T, Compare>::BinarySearchTree(std::initializer_list<T> list)
{
	for (auto i : list)
	{
		this->insert(i);
	}
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
