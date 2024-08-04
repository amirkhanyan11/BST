#include "bstree.h"

using namespace cocobolo;


template <typename T, typename node_type, typename Compare>
typename Tree<T, node_type, Compare>::size_type Tree<T, node_type, Compare>::_size(const_node_pointer root) const noexcept
{
	return (root == nullptr) ? 0 : 1 + _size(root->left) + _size(root->right);
}

template <typename T, typename node_type, typename Compare>
typename Tree<T, node_type, Compare>::size_type Tree<T, node_type, Compare>::size() const noexcept
{
	return _size(this->root);
}

template <typename T, typename node_type, typename Compare>
typename Tree<T, node_type, Compare>::size_type Tree<T, node_type, Compare>::_height(const_node_pointer root) const noexcept
{
	return (root == nullptr) ? 0 : 1 + std::max(_height(root->left),_height(root->right));
}

template <typename T, typename node_type, typename Compare>
typename Tree<T, node_type, Compare>::size_type Tree<T, node_type, Compare>::height() const noexcept
{
	return _height(this->root);
}
