
#ifndef __RBT_INSERT_TPP__
#define __RBT_INSERT_TPP__


#include "red_black_tree.h"

using namespace cocobolo;

using  namespace std;

template <typename T, typename Compare>
void RedBlackTree<T, Compare>::insert(const_reference val)
{
    this->__insert(new RBnode<T>(val, NIL, __color::RED));
}

template <typename T, typename Compare>
void RedBlackTree<T, Compare>::__insert(node_pointer z)
{
	node_pointer y = NIL;
	node_pointer x = this->root;

    while (x != NIL)
    {
        y = x;

        if (z->val < x->val) x = x->left;

        else if (z->val > x->val) x = x->right;

        else return;
    }

    z->p = y;

    if (y == NIL) this->root = z;

    else if (z->val < y->val) y->left = z;

    else y->right = z;

    _insert_fixup(z);
}

template <typename T, typename Compare>
void RedBlackTree<T, Compare>::_insert_fixup(node_pointer z)
{
    while (z->p->color == __color::RED)
    {
        if (z->p == z->p->p->left)
        {
            node_pointer y = z->p->p->right;

            if (y->color == __color::RED)
            {
                y->color = __color::BLACK;
                z->p->color = __color::BLACK;
                z->p->p->color = __color::RED;
                z = z->p->p;
            }
            else
            {
                if (z == z->p->right)
                {
                    z = z->p;
                    _lrotate(z);
                }

                z->p->color = __color::BLACK;
                z->p->p->color = __color::RED;
                _rrotate(z->p->p);
            }
        }
        else
        {
            node_pointer y = z->p->p->left;

            if (y->color == __color::RED)
            {
                y->color = __color::BLACK;
                z->p->color = __color::BLACK;
                z->p->p->color = __color::RED;
                z = z->p->p;
            }
            else
            {
                if (z == z->p->left)
                {
                    z = z->p;
                    _rrotate(z);
                }

                z->p->color = __color::BLACK;
                z->p->p->color = __color::RED;
                _lrotate(z->p->p);
            }
        }
    }
    this->root->color = __color::BLACK;
}


#endif // __RBT_INSERT_TPP__
