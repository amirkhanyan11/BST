#include "bstree.h"

using namespace cocobolo;


template <typename T, typename node_type, typename Compare>
typename Tree<T, node_type, Compare>::const_node_pointer Tree<T, node_type, Compare>::find(const_reference value) const noexcept
{
	return this->_find(value, this->m_root);
}

template <typename T, typename node_type, typename Compare>
typename Tree<T, node_type, Compare>::node_pointer Tree<T, node_type, Compare>::find(const_reference value) noexcept
{
	return const_cast<node_pointer>(this->_find(value, this->m_root));
}
