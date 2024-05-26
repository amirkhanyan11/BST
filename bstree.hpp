#include "bstree.h"
#include "_search.hpp"
#include "_traversal.hpp"
#include "_find_.hpp"
#include "_insert_remove.hpp"
#include "_predecessor_successor.hpp"
#include "_size_height.hpp"
#include "_helpers.hpp"

#include "binary_search_tree.hpp"
using namespace juju;


template <typename T>
BinarySearchTree<T>::BinarySearchTree(std::initializer_list<T> list)
{
	for (auto i : list)
	{
		this->insert(i);
	}
}

template <typename T>
Node<T>& Node<T>::operator=(Node<T>&& other)
{
	m_data = other.m_data;
	left = other.left;
	right = other.right;
	other.left = nullptr, other.right = nullptr;
}


template <typename T>
Node<T>::Node(const T& value, Node<T> *p) : m_data{value}, parent{p} {}



template <typename T, typename node_type>
Tree<T, node_type>::~Tree()
{
	_clear(m_root);
	this->m_root = nullptr;
}
