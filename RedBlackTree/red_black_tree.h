#ifndef __REDBLACKTREE__
#define __REDBLACKTREE__

#include "../Tree/bstree.h"

namespace cocobolo
{


template <typename T, typename Compare = std::less<T>>
class RedBlackTree final : public Tree<T, RBnode<T>, Compare>
{

private:

	RBnode<T> *NIL;

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

    RedBlackTree();
    RedBlackTree(std::initializer_list<value_type>);
	~RedBlackTree();

public:

	void 					insert(const_reference val) override;
	void 					remove(const_reference val) noexcept override;
	node_pointer 			find(const_reference val) noexcept override;
	const_node_pointer 		find(const_reference val) const noexcept override;


	reference 				min() noexcept;
	reference 				max() noexcept;


	template <class func>
	void			preorder(func f);

	template <class func>
	void			postorder(func f);

private:

	node_pointer 	_min(node_pointer x) noexcept;
	node_pointer 	_max(node_pointer x) noexcept;
	void			_find(const_node_pointer x, const_reference val) const noexcept;
	void			_delete(node_pointer z);
	void			_transplant(node_pointer u, node_pointer v);
    void	 		_lrotate(node_pointer x);
    void 			_rrotate(node_pointer x);
	void 			__insert(node_pointer z);
	void 			_insert_fixup(node_pointer z);
	void 			_delete_fixup(node_pointer z);

	template <class func>
	void			__preorder__(const_node_pointer root, func f);

	template <class func>
	void			__postorder__(const_node_pointer root, func f);

	// node_pointer 	_get_uncle(node_pointer  root);
	// node_pointer 	_get_sibling(node_pointer  root);
	// void				_restore(node_pointer& root);
	// void 			_recolor(node_pointer);
	// void 			_insert(const_reference value, node_pointer& root, node_pointer p = nullptr) override;

	// void 			_remove(node_pointer root) noexcept override;
	// void 			_transplant(node_pointer u, node_pointer v);
	// void 			_remove_fixup(node_pointer x);
};


// #include "red_black_tree.hpp"
#include "red_black_tree.tpp"


}







#endif // __REDBLACKTREE__
