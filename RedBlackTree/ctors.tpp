
#ifndef __RBT_CTORS_TPP__
#define __RBT_CTORS_TPP__

#include "red_black_tree.h"

using namespace cocobolo;

using  namespace std;

template <typename T>
RBnode<T>::RBnode(const T& val, RBnode* NIL, __color color)

	:  	val{val},
		p{NIL},
		left{NIL},
		right{NIL},
    	color{color} {}


template <typename T, typename Compare>
RedBlackTree<T, Compare>::RedBlackTree(std::initializer_list<value_type> lst)
{
    NIL = new RBnode<T>(T{}, nullptr, __color::BLACK);
    this->root = NIL;
    for (auto i : lst)
    {
        this->insert(i);
    }
}


template <typename T, typename Compare>
RedBlackTree<T, Compare>::RedBlackTree()
{
    NIL = new RBnode<T>(T{}, nullptr, __color::BLACK);
    this->root = NIL;
}


template <typename T, typename Compare>
RedBlackTree<T, Compare>::~RedBlackTree()
{
    postorder([](const_node_pointer node){delete node;});
    delete this->NIL;
    this->root = nullptr;
    this->NIL = nullptr;
}



#endif // __RBT_CTORS_TPP__
