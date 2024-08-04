
#include "red_black_tree.h"

using namespace cocobolo;

using  namespace std;

template <typename T>
RBnode<T>::RBnode(const T& val, RBnode* NIL, __color color)

	:  	val{val},
		parent{NIL},
		left{NIL},
		right{NIL},
    	m_color{color} {}


template <typename T, typename Compare>
RedBlackTree<T, Compare>::RedBlackTree(std::initializer_list<value_type> lst)
{
    NIL = new RBnode<T>(T{}, nullptr, __color::BLACK);
    this->m_root = NIL;
    for (auto i : lst)
    {
        this->insert(i);
    }
}


template <typename T, typename Compare>
RedBlackTree<T, Compare>::RedBlackTree()
{
    NIL = new RBnode<T>(T{}, nullptr, __color::BLACK);
    this->m_root = NIL;
}

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
    __preorder__(this->m_root, f);
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
    __postorder__(this->m_root, f);
}



template <typename T, typename Compare>
RedBlackTree<T, Compare>::~RedBlackTree()
{
    postorder([](const_node_pointer node){delete node;});
    delete this->NIL;
    this->m_root = nullptr;
    this->NIL = nullptr;
}