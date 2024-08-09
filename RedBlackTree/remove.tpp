
#ifndef __RBT_REMOVE_TPP__
#define __RBT_REMOVE_TPP__


#include "red_black_tree.h"

using namespace cocobolo;

using  namespace std;

template <typename T, typename Compare>
void RedBlackTree<T, Compare>::remove(const_reference value) noexcept
{
	node_pointer z = this->find(value);

	if (z != NIL) _delete(z);
}


template <typename T, typename Compare>
void RedBlackTree<T, Compare>::_transplant(node_pointer u, node_pointer v)
{
	if (u->p == NIL) this->root = v;

	else if (u == u->p->left) u->p->left = v;

	else u->p->right = v;

	v->p = u->p;

}

template <typename T, typename Compare>
void RedBlackTree<T, Compare>::_delete(node_pointer z)
{
	node_pointer x = NIL;
	node_pointer y = z;
	__color y_orig_color = y->color;

	if (z->left == NIL)
	{
		x = z->right;
		_transplant(z, z->right);
	}
	else if (z->right == NIL)
	{
		x = z->left;
		_transplant(z, z->left);
	}
	else
	{
		y = this->_min(z->right);
		y_orig_color = y->color;
		x = y->right;

		if (y->p == z)
		{
			x->p = y;
		}

		else
		{
			_transplant(y, y->right);
			y->right = z->right;
			y->right->p = y;
		}

		_transplant(z, y);
		y->left = z->left;
		y->left->p = y;
		y->color = z->color;
	}

	delete z;
	z = nullptr;

	if (y_orig_color == __color::BLACK)
	{
		_delete_fixup(x);
	}
}


template <typename T, typename Compare>
void RedBlackTree<T, Compare>::_delete_fixup(node_pointer x)
{
	while (x != this->root and x->color == __color::BLACK)
	{
		node_pointer w = NIL;
		if (x == x->p->left)
		{
			w = x->p->right;
			if (w->color == __color::RED) // case 1
			{
				w->color = __color::BLACK;
				x->p->color = __color::RED;
				_lrotate(x->p);
				w = x->p->right;
			}
			if (w->left->color == __color::BLACK and w->right->color == __color::BLACK) // case 2
			{
				w->color = __color::RED;
				x = x->p;
			}
			else
			{
				if (w->right->color == __color::BLACK) // case 3
				{
					w->left->color = __color::BLACK;
					w->color = __color::RED;
					_rrotate(w);
					w = x->p->right;
				}

				w->color = x->p->color; // case 4
				x->p->color = __color::BLACK;
				w->right->color = __color::BLACK;
				_lrotate(x->p);
				x = this->root;
			}
		}
		else
		{
			w = x->p->left;
			if (w->color == __color::RED) // case 1
			{
				w->color = __color::BLACK;
				x->p->color = __color::RED;
				_rrotate(x->p);
				w = x->p->left;
			}
			if (w->right->color == __color::BLACK and w->left->color == __color::BLACK) // case 2
			{
				w->color = __color::RED;
				x = x->p;
			}
			else
			{
				if (w->left->color == __color::BLACK) // case 3
				{
					w->right->color = __color::BLACK;
					w->color = __color::RED;
					_lrotate(w);
					w = x->p->left;
				}

				w->color = x->p->color; // case 4
				x->p->color = __color::BLACK;
				w->left->color = __color::BLACK;
				_rrotate(x->p);
				x = this->root;
			}
		}
	}
	x->color = __color::BLACK;
}

#endif // __RBT_REMOVE_TPP__
