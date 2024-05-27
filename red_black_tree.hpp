#include "red_black_tree.h"

using namespace cocobolo;


template <typename T>
RBnode<T>::RBnode(const T& val, __color color, RBnode* p) : Node<T>{val, p}
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
void RedBlackTree<T>::_lrotate(node_pointer root)
{
    if (root == nullptr || root->right == nullptr)
        return;

	node_pointer p = root->parent;

	node_pointer newroot = root->right;

	node_pointer tmp = newroot->left;

    root->right = tmp;

    newroot->left = root;

    if (p != nullptr)
        p->right == root ? p->right = newroot : p->left = newroot;

	else
		m_root = newroot;

}
