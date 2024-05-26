#include "bstree.h"

using namespace juju;



template <typename T, typename node_type>
node_type* Tree<T, node_type>::find(const T& value) const noexcept
{
	return Tree<T>::_find(value, this->m_root);
}
