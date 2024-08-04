
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
	node_pointer x = this->m_root;

    while (x != NIL)
    {
        y = x;

        if (z->val < x->val) x = x->left;

        else if (z->val > x->val) x = x->right;

        else return;
    }

    z->parent = y;

    if (y == NIL) this->m_root = z;

    else if (z->val < y->val) y->left = z;

    else y->right = z;

    _insert_fixup(z);
}

template <typename T, typename Compare>
void RedBlackTree<T, Compare>::_insert_fixup(node_pointer z)
{
    while (z->parent->m_color == __color::RED)
    {
        if (z->parent == z->parent->parent->left)
        {
            node_pointer y = z->parent->parent->right;

            if (y->m_color == __color::RED)
            {
                y->m_color = __color::BLACK;
                z->parent->m_color = __color::BLACK;
                z->parent->parent->m_color = __color::RED;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->right)
                {
                    z = z->parent;
                    _lrotate(z);
                }

                z->parent->m_color = __color::BLACK;
                z->parent->parent->m_color = __color::RED;
                _rrotate(z->parent->parent);
            }
        }
        else
        {
            node_pointer y = z->parent->parent->left;

            if (y->m_color == __color::RED)
            {
                y->m_color = __color::BLACK;
                z->parent->m_color = __color::BLACK;
                z->parent->parent->m_color = __color::RED;
                z = z->parent->parent;
            }
            else
            {
                if (z == z->parent->left)
                {
                    z = z->parent;
                    _rrotate(z);
                }

                z->parent->m_color = __color::BLACK;
                z->parent->parent->m_color = __color::RED;
                _lrotate(z->parent->parent);
            }
        }
    }
    this->m_root->m_color = __color::BLACK;
}

























#endif // __RBT_INSERT_TPP__
