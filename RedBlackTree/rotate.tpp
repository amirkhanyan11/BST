
#ifndef __RBT_ROTATE_TPP__
#define __RBT_ROTATE_TPP__


#include "red_black_tree.h"

using namespace cocobolo;

using  namespace std;


template <typename T, typename Compare>
void RedBlackTree<T, Compare>::_lrotate(node_pointer x)
{

    node_pointer y = x->right;

    x->right = y->left;

    if (y->left != NIL) y->left->p = x;

    y->p = x->p;

    if (x->p == NIL) this->root = y;

    else if (x == x->p->left) x->p->left = y;

    else x->p->right = y;

    y->left = x;

    x->p = y;
}

template <typename T, typename Compare>
void RedBlackTree<T, Compare>::_rrotate(node_pointer x)
{
    node_pointer y = x->left;

    x->left = y->right;

    if (y->right != NIL) y->right->p = x;

    y->p = x->p;

    if (x->p == NIL) this->root = y;

    else if (x == x->p->left) x->p->left = y;

    else x->p->right = y;

    y->right = x;

    x->p = y;
}


#endif // __RBT_ROTATE_TPP__
