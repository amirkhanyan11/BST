
#ifndef __RBT_FIND_TPP__
#define __RBT_FIND_TPP__


#include "red_black_tree.h"

using namespace cocobolo;

using  namespace std;


template <typename T, typename Compare>
RedBlackTree<T, Compare>::node_pointer RedBlackTree<T, Compare>::find(const_reference val)  noexcept
{
	return const_cast<node_pointer>
	(
		static_cast<const RedBlackTree<T, Compare> *>(this)->find(val)
	);
}

template <typename T, typename Compare>
RedBlackTree<T, Compare>::const_node_pointer RedBlackTree<T, Compare>::find(const_reference val) const noexcept
{
	return this->_find(this->root);
}


template <typename T, typename Compare>
void RedBlackTree<T, Compare>::_find(const_node_pointer x, const_reference val) const noexcept
{
	if (x == NIL) return NIL;

	if (comp(x->val, val)) return _find(x->left, val);

	else if (comp(val, x->val)) return _find(x->right, val);

	return x;
}


template <typename T, typename Compare>
RedBlackTree<T, Compare>::reference RedBlackTree<T, Compare>::min() noexcept
{
	return this->_min(this->root)->val;
}

template <typename T, typename Compare>
RedBlackTree<T, Compare>::reference RedBlackTree<T, Compare>::max() noexcept
{
	return this->_max(this->root)->val;
}

template <typename T, typename Compare>
RedBlackTree<T, Compare>::node_pointer RedBlackTree<T, Compare>::_min(node_pointer x) noexcept
{
	return (x == NIL || x->left == NIL) ? x : _min(x->left);
}

template <typename T, typename Compare>
RedBlackTree<T, Compare>::node_pointer RedBlackTree<T, Compare>::_max(node_pointer x) noexcept
{
	return (x == NIL || x->right == NIL) ? x : _max(x->right);
}


#endif // __RBT_FIND_TPP__
