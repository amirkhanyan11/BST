#include "red_black_tree.h"

using namespace cocobolo;


template <typename T>
RBnode<T>::RBnode(const T& val, RBnode* p, __color color)

	:  	m_data{val},
		parent{p},
    	m_color{color}{}



template <typename T>
RedBlackTree<T>::RedBlackTree(std::initializer_list<value_type> lst)
{
    for (auto i : lst)
    {
        this->insert(i);
    }
}


// template <typename T>
// void RedBlackTree<T>::insert(const_reference val)
// {

// }


template <typename T>
void RedBlackTree<T>::_lrotate(node_pointer& root)
{
    if (root == nullptr || root->right == nullptr)
        return;

	node_pointer p = root->parent;

	node_pointer newroot = root->right;

    root->right = newroot->left;

	if (newroot->left != nullptr)
    	newroot->left->parent = root;

    newroot->left = root;

	newroot->parent = p;

	root->parent = newroot;

    if (p != nullptr)
        p->right == root ? p->right = newroot : p->left = newroot;

	else
		this->m_root = newroot;

}


template <typename T>
void RedBlackTree<T>::_rrotate(node_pointer& root)
{
    if (root == nullptr || root->left == nullptr)
        return;

	node_pointer p = root->parent;

	node_pointer newroot = root->left;

    root->left = newroot->right;

	if (newroot->right != nullptr)
    	newroot->right->parent = root;

    newroot->right = root;

	newroot->parent = p;

	root->parent = newroot;

    if (p != nullptr)
        p->right == root ? p->right = newroot : p->left = newroot;

	else
		this->m_root = newroot;

}

template <typename T>
typename RedBlackTree<T>::node_pointer 	 RedBlackTree<T>::_get_uncle(typename RedBlackTree<T>::node_pointer root)
{
	auto p = root->parent;

	if (p == nullptr) return nullptr;

	auto gp = p->parent;

	if (gp == nullptr) return nullptr;

	return (gp->left == p) ? gp->right : gp->left;
}

template <typename T>
void RedBlackTree<T>::_insert(const_reference value, node_pointer& root, node_pointer p)
{
	if (root == nullptr)
	{
		root = new node_type{value, p, __color::RED};
		_restore(root);
		return;
	}

	else if (root->m_data < value)
		this->_insert(value, root->right, root);

	else if (root->m_data > value)
		this->_insert(value, root->left, root);
}

template <typename T>
void RedBlackTree<T>::_recolor(node_pointer root)
{
	root->m_color = (root->m_color == __color::RED) ? __color::BLACK : __color::RED;
}

template <typename T>
void RedBlackTree<T>::_restore(node_pointer& root)
{
	if (root == this->m_root)
	{
		root->m_color = __color::BLACK;
		return;
	}

	node_pointer uncle = this->_get_uncle(root);

	if (uncle == nullptr && (root->parent == nullptr || root->parent->parent == nullptr)) return; // ??

	__color uncle_color = (uncle == nullptr) ? __color::BLACK : uncle->m_color;

	switch (uncle_color)
	{
		case __color::RED:
		{
			_recolor (root->parent);
			_recolor (root->parent->parent);
			_recolor (uncle);

			_restore(root->parent->parent); // idk
			break ;
		}
		case __color::BLACK:
		{
			// triangle
			if (root->parent->left == root && root->parent->parent->right == root->parent)
			{
				_rrotate(root->parent);
				_restore(root->right);
			}
			else if (root->parent->right == root && root->parent->parent->left == root->parent)
			{
				_lrotate(root->parent);
				_restore(root->left);
			}

			// line
			else if (root->parent->right == root && root->parent->parent->right == root->parent)
			{
				_recolor(root->parent);
				_recolor(root->parent->parent);
				_lrotate(root->parent->parent);
			}

			else if (root->parent->left == root && root->parent->parent->left == root->parent)
			{
				_recolor(root->parent);
				_recolor(root->parent->parent);
				_rrotate(root->parent->parent);
			}
		}
	}


}
