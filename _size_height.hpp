#include "bstree.h"

using namespace juju;


template <typename T, typename node_type>
typename Tree<T, node_type>::size_type Tree<T, node_type>::_size(const_node_pointer root) const noexcept
{
	return (root == nullptr) ? 0 : 1 + _size(root->left) + _size(root->right);
}

template <typename T, typename node_type>
typename Tree<T, node_type>::size_type Tree<T, node_type>::size() const noexcept
{
	return _size(this->m_root);
}

template <typename T, typename node_type>
typename Tree<T, node_type>::size_type Tree<T, node_type>::_height(const_node_pointer root) const noexcept
{
	return (root == nullptr) ? 0 : 1 + std::max(_height(root->left),_height(root->right));
}

template <typename T, typename node_type>
typename Tree<T, node_type>::size_type Tree<T, node_type>::height() const noexcept
{
	return _height(this->m_root);
}