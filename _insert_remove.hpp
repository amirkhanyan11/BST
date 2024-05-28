#include "bstree.h"

using namespace cocobolo;

template <typename T, typename node_type, typename Compare>
void Tree<T, node_type, Compare>::insert(const_reference value)
{
	this->_insert(value, this->m_root);
}

template <typename T, typename node_type, typename Compare>
typename Tree<T, node_type, Compare>::size_type Tree<T, node_type, Compare>::_childcount(node_pointer root) const noexcept
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


template <typename T, typename node_type, typename Compare>
void Tree<T, node_type, Compare>::remove(const_reference value) noexcept
{
	node_pointer root = this->find(value);

	if (root == nullptr)
	{
		return;
	}

	this->_remove(root);

}


template <typename T, typename node_type, typename Compare>
void Tree<T, node_type, Compare>::_clear(node_pointer root) noexcept
{
	if (root == nullptr)
	{
		return;
	}

	this->_clear(root->left);
	this->_clear(root->right);
	this->_remove(root);
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

		static_cast<const Node<T>*>(this)->get_value()
	);
}

template <typename T, typename node_type, typename Compare>
void Tree<T, node_type, Compare>::_remove(node_type* root) noexcept
{
	if (root == m_root)
	{
		delete m_root;
		m_root = nullptr;
		return;
	}

	node_pointer tmp = nullptr;

    const size_type children = this->_childcount(root);
    node_pointer parent = root->parent;

	switch (children)
	{
		case 1:
		{
			tmp = (root->left == nullptr) ? root->right : root->left;
			(parent->left == root) ? parent->left = tmp : parent->right = tmp;
			delete root;
			break;
		}

		case 2:
		{
			tmp = this->successor(root->m_data);

			T data_t = tmp->m_data;

			this->_remove(tmp);

			root->m_data = data_t;

			break;
		}

		case 0:
			delete root;
			(parent->left == root) ? parent->left = nullptr : parent->right = nullptr;
	}
}


template <typename T, typename node_type, typename Compare>
typename Tree<T, node_type, Compare>::const_node_pointer Tree<T, node_type, Compare>::_find(Tree<T, node_type, Compare>::const_reference value, Tree<T, node_type, Compare>::node_pointer root) const noexcept
{
	if (root == nullptr)
	{
		return nullptr;
	}

	if (this->comp(value, root->m_data))
    {
		return this->_find(value, root->left);
    }

	else if (this->comp(root->m_data, value))
	{
		return this->_find(value, root->right);
	}

	else
	{
		return root;
	}
}
