#include "bstree.h"

using namespace juju;

template <typename T, typename node_type>
typename Tree<T, node_type>::const_node_pointer Tree<T, node_type>::find_min() const noexcept
{
	return _find_min(this->m_root);
}

template <typename T, typename node_type>
typename Tree<T, node_type>::const_node_pointer Tree<T, node_type>::find_max() const noexcept
{
	return _find_max(this->m_root);
}

template <typename T, typename node_type>
typename Tree<T, node_type>::node_pointer Tree<T, node_type>::find_min() noexcept
{
	return const_cast<Node*>(

		static_cast<const Tree*>(this)->find_min()
	);
}

template <typename T, typename node_type>
typename Tree<T, node_type>::node_pointer Tree<T, node_type>::find_max() noexcept
{
	return const_cast<Node*>(

		static_cast<const Tree*>(this)->find_max()
	);
}

template <typename T, typename node_type>
typename Tree<T, node_type>::const_node_pointer Tree<T, node_type>::_find_min(const_node_pointer root) const noexcept
{
	if (root->left == nullptr)
	{
		return root;
	}

	return _find_min(root->left);
}

template <typename T, typename node_type>
typename Tree<T, node_type>::const_node_pointer Tree<T, node_type>::_find_max(const_node_pointer root) const noexcept
{
	if (root->right == nullptr)
	{
		return root;
	}

	return _find_max(root->right);
}
