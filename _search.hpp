#include "bstree.h"

using namespace juju;


template <typename T, typename node_type>
node_type* Tree<T, node_type>::find(const T& value) const noexcept
{
	return this->_find(value, this->m_root);
}
