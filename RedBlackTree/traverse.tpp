
#ifndef __RBT_TRAVERSE_TPP__
#define __RBT_TRAVERSE_TPP__


#include "red_black_tree.h"

using namespace cocobolo;

using  namespace std;


template <typename T, typename Compare>
template <class func>
void RedBlackTree<T, Compare>::__preorder__(const_node_pointer root, func f)
{
    if (root == this->NIL) return;

    f(root);
    __preorder__(root->left, f);
    __preorder__(root->right, f);
}

template <typename T, typename Compare>
template <class func>
void RedBlackTree<T, Compare>::preorder(func f)
{
    __preorder__(this->root, f);
}

template <typename T, typename Compare>
template <class func>
void RedBlackTree<T, Compare>::__postorder__(const_node_pointer root, func f)
{
    if (root == this->NIL) return;

    __postorder__(root->left, f);
    __postorder__(root->right, f);
    f(root);
}

template <typename T, typename Compare>
template <class func>
void RedBlackTree<T, Compare>::postorder(func f)
{
    __postorder__(this->root, f);
}



#endif // __RBT_TRAVERSE_TPP__
