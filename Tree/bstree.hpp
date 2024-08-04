#include "bstree.h"
#include "_search.hpp"
#include "_traversal.hpp"
#include "_find_.hpp"
#include "_insert_remove.hpp"
#include "_predecessor_successor.hpp"
#include "_size_height.hpp"
#include "_helpers.hpp"

#include "binary_search_tree.hpp"
using namespace cocobolo;



template <typename T>
Node<T>& Node<T>::operator=(Node<T>&& other)
{
	val = other.val;
	left = other.left;
	right = other.right;
	other.left = nullptr, other.right = nullptr;
}


template <typename T>
Node<T>::Node(const T& value, Node<T> *p) : val{value}, p{p} {}



template <typename T, typename node_type, typename Compare>
Tree<T, node_type, Compare>::~Tree()
{
	_clear(m_root);
	this->m_root = nullptr;
}
