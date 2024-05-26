#include "bstree.h"

using namespace juju;

template <typename T, typename node_type>
void Tree<T, node_type>::insert(const T& value)
{
	_insert(value, this->m_root);
}

template <typename T, typename node_type>
typename Tree<T, node_type>::size_type Tree<T, node_type>::_childcount(node_pointer root) const noexcept
{

	if (root->left == nullptr && root->right == nullptr)
	{
		return 0;
	}

	if (root->left != nullptr && root->right != nullptr)
	{
		return 2;
	}

	return 1;
}


template <typename T, typename node_type>
void Tree<T, node_type>::remove(const T& value) noexcept
{
	if (m_root->m_data == value)
	{
		delete m_root;
		return;
	}

	node_pointer root = this->find(value);

	if (root == nullptr)
	{
		return;
	}

	_remove(root, root->parent, _childcount(root));

}


template <typename T, typename node_type>
void Tree<T, node_type>::_clear(node_pointer root) noexcept
{
	if (root == nullptr)
	{
		return;
	}

	_clear(root->left);
	_clear(root->right);
	remove(root->m_data);
}

template <typename T>
const T& Node<T>::get_value() const noexcept
{
	return this->m_data;
}

template <typename T>
T& Node<T>::get_value() noexcept
{
	return const_cast<T&>(

		static_cast<const node_pointer>(this)->get_value()
	);
}