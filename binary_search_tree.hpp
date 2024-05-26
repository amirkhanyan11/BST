#include "bstree.h"

using namespace juju;


template <typename T>
void BinarySearchTree<T>::_insert(const_reference value, node_pointer& root, node_pointer p)
{
	if (root == nullptr)
	{
		root = new Node{value, p};
		return;
	}

	else if (root->m_data < value)
		_insert(value, root->right, root);

	else if (root->m_data > value)
		_insert(value, root->left, root);
}

template <typename T>
void BinarySearchTree<T>::_remove(node_pointer root, node_pointer parent, const size_t children) noexcept
{

	node_pointer tmp = nullptr;


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

			_remove(tmp, tmp->parent, this->_childcount(tmp));

			root->m_data = data_t;

			break;
		}

		case 0:
			delete root;
			(parent->left == root) ? parent->left = nullptr : parent->right = nullptr;
	}
}


template <typename T>
typename BinarySearchTree<T>::node_pointer BinarySearchTree<T>::_find(const_reference value, node_pointer root) const noexcept
{
	if (root == nullptr)
	{
		return nullptr;
	}

	if (root->m_data == value)
	{
		return root;
	}

	else if (root->m_data < value)
	{
		return _find(value, root->right);
	}

	else
    {
		return _find(value, root->left);
    }
}