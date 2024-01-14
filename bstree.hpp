using namespace juju;
#include "_search.hpp"
#include "_traversal.hpp"
#include "_find_.hpp"
#include "_insert_remove.hpp"
#include "_predecessor_successor.hpp"

template <typename T>
Tree<T>::Tree(std::initializer_list<T> list)
{
	for (auto i : list)
	{
		this->insert(i);
	}
}


template <typename T>
typename Tree<T>::Node::Node& Tree<T>::Node::operator=(Node&& other)
{
	m_data = other.m_data;
	left = other.left;
	right = other.right;
	other.left = nullptr, other.right = nullptr;
}


template <typename T>
Tree<T>::Node::Node(const T& value) : m_data{value} {}



template <typename T>
Tree<T>::~Tree()
{
	_clear(m_root);
}
