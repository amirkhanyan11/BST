#include "bstree.h"

using namespace cocobolo;


template <typename T, typename node_type>
template <typename func>
void Tree<T, node_type>::_inorder(const_node_pointer root, func f) const noexcept
{
	if(root == nullptr)
	{
		return;
	}

	_inorder(root->left, f);

	f(root);

	_inorder(root->right, f);
}

template <typename T, typename node_type>
template <typename func>
void Tree<T, node_type>::_preorder(const_node_pointer root, func f) const noexcept
{
	if(root == nullptr)
	{
		return;
	}

	f(root);

	_preorder(root->left, f);

	_preorder(root->right, f);
}

template <typename T, typename node_type>
template <typename func>
void Tree<T, node_type>::_postorder(const_node_pointer root, func f) const noexcept
{
	if(root == nullptr)
	{
		return;
	}


	_postorder(root->left, f);

	_postorder(root->right, f);

	f(root);

}


template <typename T, typename node_type>
template <typename func>
void Tree<T, node_type>::inorder(func f) const noexcept
{
	_inorder(this->m_root, f);
}

template <typename T, typename node_type>
template <typename func>
void Tree<T, node_type>::preorder(func f) const noexcept
{
	_preorder(this->m_root, f);
}

template <typename T, typename node_type>
template <typename func>
void Tree<T, node_type>::postorder(func f) const noexcept
{
	_postorder(this->m_root, f);
}
