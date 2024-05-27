#ifndef __REDBLACKTREE__
#define __REDBLACKTREE__

#include "bstree.h"


namespace cocobolo
{

enum class __color {RED, BLACK};

template <typename T>
struct RBnode : Node<T>
{

public:

    __color m_color = __color::BLACK;

    RBnode(const T&, __color color = __color::RED, RBnode* p = nullptr);
};


template <typename T>
class RedBlackTree : public Tree<T, RBnode<T>>
{

public:

	using value_type 		 =	T;
	using reference          = 	value_type &;
	using const_reference    = 	const value_type &;
	using size_type          = 	std::size_t;
	using pointer 			 = 	value_type *;
	using const_pointer 	 = 	const value_type *;
	using node_pointer 		 =  RBnode<T> *;
	using const_node_pointer =	const  RBnode<T> *;

public:

    RedBlackTree() = default;
    RedBlackTree(std::initializer_list<value_type>);

	void 	_insert(const_reference value, node_pointer& root, node_pointer p = nullptr) override
	{
		cout << "foo\n";
	}


public: // x

    void _lrotate(node_pointer root);
    void _rrotate(node_pointer root);

    // void foo()
    // {
    //     this->_lrotate(this->m_root);
    // }

public:


    // void insert(const_reference) override;
    // void remove(const_reference) override noexcept;


};



#include "red_black_tree.hpp"


}







#endif // __REDBLACKTREE__
