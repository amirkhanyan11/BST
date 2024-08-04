
#ifndef __RBT_ROTATE_TPP__
#define __RBT_ROTATE_TPP__


#include "red_black_tree.h"

using namespace cocobolo;

using  namespace std;


template <typename T, typename Compare>
void RedBlackTree<T, Compare>::_lrotate(node_pointer x)
{
    if (!x || !x->right)
        return;

    node_pointer y = x->right;

    x->right = y->left;

    if (y->left != NIL) y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == NIL) this->m_root = y;

    else if (x == x->parent->left) x->parent->left = y;

    else x->parent->right = y;

    y->left = x;

    x->parent = y;
}

template <typename T, typename Compare>
void RedBlackTree<T, Compare>::_rrotate(node_pointer x)
{
    if (!x || !x->left)
        return;

    node_pointer y = x->left;

    x->left = y->right;

    if (y->right != NIL) y->right->parent = x;

    y->parent = x->parent;

    if (x->parent == NIL) this->m_root = y;

    else if (x == x->parent->left) x->parent->left = y;

    else x->parent->right = y;

    y->right = x;

    x->parent = y;
}






#endif // __RBT_ROTATE_TPP__
