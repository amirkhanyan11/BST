#include "bstree.h"

using namespace cocobolo;


template <typename T, typename node_type, typename Compare>
typename Tree<T, node_type, Compare>::node_pointer Tree<T, node_type, Compare>::_predecessor(node_pointer root) noexcept
{
	if(root->left == nullptr)
	{
		return root;
	}
	return const_cast<Tree<T, node_type, Compare>::node_pointer>(_find_max(root->left));
}

template <typename T, typename node_type, typename Compare>
typename Tree<T, node_type, Compare>::node_pointer Tree<T, node_type, Compare>::_successor(node_pointer root) noexcept
{
	if(root->right == nullptr)
	{
		return root;
	}
	return const_cast<Tree<T, node_type, Compare>::node_pointer>(_find_min(root->right));
}


template <typename T, typename node_type, typename Compare>
typename Tree<T, node_type, Compare>::node_pointer Tree<T, node_type, Compare>::successor(const_reference value) noexcept
{
	return Tree<T, node_type, Compare>::_successor(find(value));
}

template <typename T, typename node_type, typename Compare>
typename Tree<T, node_type, Compare>::node_pointer Tree<T, node_type, Compare>::predecessor(const_reference value) noexcept
{
	return Tree<T, node_type, Compare>::_predecessor(find(value));
}
