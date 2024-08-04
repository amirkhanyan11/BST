#include "bstree.h"

using namespace cocobolo;

template <typename T, typename node_type, typename Compare>
typename Tree<T, node_type, Compare>::const_node_pointer Tree<T, node_type, Compare>::find_min() const noexcept
{
	return _find_min(this->m_root);
}

template <typename T, typename node_type, typename Compare>
typename Tree<T, node_type, Compare>::const_node_pointer Tree<T, node_type, Compare>::find_max() const noexcept
{
	return _find_max(this->m_root);
}

template <typename T, typename node_type, typename Compare>
typename Tree<T, node_type, Compare>::node_pointer Tree<T, node_type, Compare>::find_min() noexcept
{
	return const_cast<Tree<T, node_type, Compare>::node_pointer>(

		static_cast<const Tree*>(this)->find_min()
	);
}

template <typename T, typename node_type, typename Compare>
typename Tree<T, node_type, Compare>::node_pointer Tree<T, node_type, Compare>::find_max() noexcept
{
	return const_cast<Tree<T, node_type, Compare>::node_pointer>(

		static_cast<const Tree*>(this)->find_max()
	);
}

template <typename T, typename node_type, typename Compare>
typename Tree<T, node_type, Compare>::const_node_pointer Tree<T, node_type, Compare>::_find_min(const_node_pointer root) const noexcept
{
	if (root->left == nullptr)
	{
		return root;
	}

	return _find_min(root->left);
}

template <typename T, typename node_type, typename Compare>
typename Tree<T, node_type, Compare>::const_node_pointer Tree<T, node_type, Compare>::_find_max(const_node_pointer root) const noexcept
{
	if (root->right == nullptr)
	{
		return root;
	}

	return _find_max(root->right);
}
