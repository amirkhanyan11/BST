#include "red_black_tree.h"

using namespace cocobolo;

using namespace std;




// template <typename T, typename Compare>
// void RedBlackTree<T, Compare>::insert(const_reference val)
// {

// }


template <typename T, typename Compare>
void RedBlackTree<T, Compare>::_lrotate(node_pointer root)
{
    if (!root || !root->right)
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


template <typename T, typename Compare>
void RedBlackTree<T, Compare>::_rrotate(node_pointer root)
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

	// if (root->val == 15)
	root->parent = newroot;


    if (p != nullptr)
        p->right == root ? p->right = newroot : p->left = newroot;

	else
		this->m_root = newroot;

}

template <typename T, typename Compare>
typename RedBlackTree<T, Compare>::node_pointer 	 RedBlackTree<T, Compare>::_get_uncle(typename RedBlackTree<T, Compare>::node_pointer root)
{
	auto p = root->parent;

	if (p == nullptr) return nullptr;

	auto gp = p->parent;

	if (gp == nullptr) return nullptr;

	return (gp->left == p) ? gp->right : gp->left;
}

template <typename T, typename Compare>
typename RedBlackTree<T, Compare>::node_pointer 	 RedBlackTree<T, Compare>::_get_sibling(typename RedBlackTree<T, Compare>::node_pointer root)
{
	auto p = root->parent;

	if (p == nullptr) return nullptr;

	return (p->left == root) ? p->right : p->left;
}

template <typename T, typename Compare>
void RedBlackTree<T, Compare>::_insert(const_reference value, node_pointer& root, node_pointer p)
{
	if (root == nullptr)
	{
		root = new node_type{value, p, __color::RED};
		_restore(root);
		return;
	}

	else if (this->comp(root->val, value))
		this->_insert(value, root->right, root);

	else if (this->comp(value, root->val))
		this->_insert(value, root->left, root);
}

template <typename T, typename Compare>
void RedBlackTree<T, Compare>::_recolor(node_pointer root)
{
	root->m_color = (root->m_color == __color::RED) ? __color::BLACK : __color::RED;
}

template <typename T, typename Compare>
void RedBlackTree<T, Compare>::_restore(node_pointer& root)
{
	if (root == this->m_root)
	{
		root->m_color = __color::BLACK;
		return;
	}

	if (root->parent->m_color == __color::BLACK)
		return;

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
				// if (root->val == 12)
				// 	std::cout << root->parent->val << std::endl;
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



template <typename T, typename Compare>
void  RedBlackTree<T, Compare>::_transplant(node_pointer u, node_pointer v)
{
	if (u == nullptr) return;

	if (u == this->m_root)
	{
		this->m_root = v;
	}
	else if (u == u->parent->left)
	{
		u->parent->left = v;
	}
	else if (u == u->parent->right)
	{
		u->parent->right = v;
	}

	if (v != nullptr) v->parent = u->parent;
}



template <typename T, typename Compare>
void  RedBlackTree<T, Compare>::_remove(node_pointer z) noexcept
{

	if (z == nullptr) return;

	if (z->left == nullptr)
	{
		_transplant(z, z->right);
		if (z->m_color == cocobolo::__color::BLACK)
		{
			_remove_fixup(z->right);
		}
	}

	if (z->right == nullptr)
	{
		_transplant(z, z->left);
		if (z->m_color == cocobolo::__color::BLACK)
		{
			_remove_fixup(z->left);
		}
	}

	if (z->left != nullptr && z->right != nullptr) // neither is NIL
	{
		node_pointer x = this->_successor(z);
		cocobolo::__color color = x->m_color;

		// std::cout << x->val << std::endl;

		if (x != z->right)
		{
			_transplant(x, x->right);

			x->right = z->right;
			x->left = z->left;
			_transplant(z, x);
		}
		// if (z->m_color == cocobolo::__color::BLACK)
		// {
		// 	// idk
		// }
	}


	delete z;

}

template <typename T, typename Compare>
void	RedBlackTree<T, Compare>::_remove_fixup(node_pointer x)
{
	while (x != this->m_root && x->m_color == __color::BLACK)
	{
		node_pointer w = _get_sibling(x);

		cocobolo::__color color = w->m_color;

		switch (color)
		{
			case __color::RED:
			{
				w->m_color = __color::BLACK;
				x->parent->m_color = __color::RED;
				this->_lrotate(x->parent);
				w = this->_get_sibling(x); // rec
				break;
			}

			case __color::BLACK:
			{
				cocobolo::__color left_color = (w->left == nullptr) ? __color::BLACK : w->left->m_color;
				cocobolo::__color right_color = (w->right == nullptr) ? __color::BLACK : w->right->m_color;

				if (left_color == __color::BLACK && right_color == __color::BLACK)
				{
					w->m_color = __color::RED;
					x = x->parent; // rec
				}

				else if (left_color == __color::RED && right_color == __color::BLACK)
				{
					w->left->m_color = __color::BLACK;
					w->m_color = __color::RED;
					this->_rrotate(w);
					w = this->_get_sibling(x);
				}

				else if (right_color == __color::RED)
				{
					w->m_color = x->parent->m_color;
					x->parent->m_color = __color::BLACK;
					w->right->m_color = __color::BLACK;
					this->_lrotate(x->parent);
					x = this->m_root;
				}
			}
		}
		x->m_color = __color::BLACK;
	}
}
