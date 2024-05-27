#ifndef __REDBLACKTREE__
#define __REDBLACKTREE__

#include "bstree.h"


namespace cocobolo
{




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
	using node_type			 =	RBnode<T>;
	using node_pointer 		 =  node_type *;
	using const_node_pointer =	const  node_type *;

public:

    RedBlackTree() = default;
    RedBlackTree(std::initializer_list<value_type>);
	virtual ~RedBlackTree() = default;



private: // x

    void	 		_lrotate(node_pointer& root);
    void 			_rrotate(node_pointer& root);
	node_pointer 	_get_uncle(node_pointer  root);
	void			_restore(node_pointer& root);
	void 			_recolor(node_pointer);
	void 			_insert(const_reference value, node_pointer& root, node_pointer p = nullptr) override;

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
