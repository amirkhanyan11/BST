#include "bstree.h"

using namespace juju;


template <typename T, typename node_type>
typename Tree<T, node_type>::const_node_pointer Tree<T, node_type>::find(const_reference value) const noexcept
{
	return this->_find(value, this->m_root);
}

template <typename T, typename node_type>
typename Tree<T, node_type>::node_pointer Tree<T, node_type>::find(const_reference value) noexcept
{
	return const_cast<node_pointer>(this->_find(value, this->m_root));
}
