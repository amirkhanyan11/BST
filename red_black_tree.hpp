#include "red_black_tree.h"

using namespace juju;


template <typename T>
RedBlackTree<T>::RBnode::RBnode(const_reference val, __color color, RBnode* p) : Tree<value_type>::Node{val, p}
{
    m_color = color;
}



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
void RedBlackTree<T>::_lrotate(typename Tree<T>::Node*& root)
{
    if (root == nullptr || root->right == nullptr)
        return;

    Tree<T>::Node* p = root->parent;

    Tree<T>::Node *newroot = root->right;

    Tree<T>::Node *tmp = newroot->left;

    root->right = tmp;

    newroot->left = root;

    if (p != nullptr)
        p->right == root ? p->right = newroot : p->left = newroot;
    
}