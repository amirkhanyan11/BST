#include "bstree.h"

using namespace cocobolo;

template <typename T, typename node_type, typename Compare>
void Tree<T, node_type, Compare>::insert(const_reference value)
{
	// this->_insert(value, this->m_root);
	return;
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
	delete root;
}

template <typename T>
const T& Node<T>::get_value() const noexcept
{
	return this->val;
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
    node_pointer p = root->p;

	switch (children)
	{
		case 1:
		{
			tmp = (root->left == nullptr) ? root->right : root->left;
			(p->left == root) ? p->left = tmp : p->right = tmp;
			delete root;
			break;
		}

		case 2:
		{
			tmp = this->successor(root->val);

			T data_t = tmp->val;

			this->_remove(tmp);

			root->val = data_t;

			break;
		}

		case 0:
			delete root;
			(p->left == root) ? p->left = nullptr : p->right = nullptr;
	}
}


template <typename T, typename node_type, typename Compare>
typename Tree<T, node_type, Compare>::const_node_pointer Tree<T, node_type, Compare>::_find(Tree<T, node_type, Compare>::const_reference value, Tree<T, node_type, Compare>::node_pointer root) const noexcept
{
	if (root == nullptr)
	{
		return nullptr;
	}

	if (this->comp(value, root->val))
    {
		return this->_find(value, root->left);
    }

	else if (this->comp(root->val, value))
	{
		return this->_find(value, root->right);
	}

	else
	{
		return root;
	}
}
