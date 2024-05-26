#include "bstree.h"

using namespace juju;


template <typename T, typename node_type>
typename Tree<T, node_type>::node_pointer Tree<T, node_type>::_predecessor(node_pointer root) noexcept
{
	if(root->left == nullptr)
	{
		return root;
	}
	return const_cast<Tree<T, node_type>::node_pointer>(_find_max(root->left));
}

template <typename T, typename node_type>
typename Tree<T, node_type>::node_pointer Tree<T, node_type>::_successor(node_pointer root) noexcept
{
	if(root->right == nullptr)
	{
		return root;
	}
	return const_cast<Tree<T, node_type>::node_pointer>(_find_min(root->right));
}


template <typename T, typename node_type>
typename Tree<T, node_type>::node_pointer Tree<T, node_type>::successor(const_reference value) noexcept
{
	return Tree<T, node_type>::_successor(find(value));
}

template <typename T, typename node_type>
typename Tree<T, node_type>::node_pointer Tree<T, node_type>::predecessor(const_reference value) noexcept
{
	return Tree<T, node_type>::_predecessor(find(value));
}
