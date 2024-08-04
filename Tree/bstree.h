#ifndef __BSTREE__
#define __BSTREE__
#include <iostream>

namespace cocobolo
{

	// template <typename T>
	// struct Node;

	// template <typename T, typename node_type = Node<T>>
	// class Tree;

	enum class __color {RED, BLACK};

	template <typename T>
	struct Node
	{
	public:

		// friend class Tree;
		Node(const T&, Node* p = nullptr);

		Node& 		operator=(Node&& other);
		const T& 	get_value() const noexcept;
		T& 			get_value() noexcept;

	public:

		T val = T{};

		Node	*left{nullptr};
		Node	*right{nullptr};
		Node	*p{nullptr};
	};


	template <typename T>
	struct RBnode
	{

	public:

		__color color = __color::BLACK;
		RBnode(const T&,  RBnode* NIL, __color color = __color::RED);

	public:

		T val = T{};
		RBnode	*left	{nullptr};
		RBnode	*right  {nullptr};
		RBnode	*p {nullptr};
	};



	template <typename T, typename node_type = Node<T>, typename Compare = std::less<T>>
	class Tree                                          // abstract
	{

	public:

		using value_type 		 =	T;
		using reference          = 	value_type &;
		using const_reference    = 	const value_type &;
		using size_type          = 	std::size_t;
		using pointer 			 = 	value_type *;
		using const_pointer 	 = 	const value_type *;
		using node_pointer 		 =  node_type *;
		using const_node_pointer =	const  node_type *;


		virtual ~Tree();

	protected:


		node_pointer root = nullptr;
		Compare 	 comp 	= Compare{};

	private:

		// virtual void 				_insert(const_reference value, node_pointer& root, node_pointer p = nullptr);
		virtual void 				_remove(node_pointer) noexcept;
		virtual const_node_pointer 	_find(const_reference value, node_pointer root) const noexcept;

	private:

		template <class func>
		void 	_inorder(const_node_pointer, func f) const noexcept;

		template <class func>
		void 	_preorder(const_node_pointer, func f) const noexcept;

		template <class func>
		void 	_postorder(const_node_pointer, func f) const noexcept;

	protected:

		const_node_pointer	_find_min(const_node_pointer) const noexcept;
		const_node_pointer  _find_max(const_node_pointer) const noexcept;
		node_pointer 		_predecessor(node_pointer) noexcept;
		node_pointer 		_successor(node_pointer) noexcept;
		void 				_clear(node_pointer) noexcept;
		size_type 			_size(const_node_pointer) const noexcept;
		size_type 			_height(const_node_pointer) const noexcept;

		size_type 			_childcount(node_pointer) const noexcept;

	public:

		template <class func>
		void 	inorder(func f) const noexcept;

		template <class func>
		void 	postorder(func f) const noexcept;

		template <class func>
		void 	preorder(func f) const noexcept;

		virtual void 					insert(const_reference value);
		virtual void 					remove(const_reference value) noexcept;
		virtual node_pointer 			find(const_reference value) noexcept;
		virtual const_node_pointer 		find(const_reference value) const noexcept;

		node_pointer 			find_min() noexcept;
		node_pointer 			find_max() noexcept;
		const_node_pointer		find_min() const noexcept;
		const_node_pointer		find_max() const noexcept;
		node_pointer 			predecessor(const_reference) noexcept;
		node_pointer 			successor(const_reference) noexcept;
		size_type 				size() const noexcept;
		size_type 				height() const noexcept;
	};




template <typename T, typename Compare = std::less<T>>
class BinarySearchTree final : public Tree<T, Node<T>, Compare>
{

public:

	using value_type 		 =	T;
	using reference          = 	value_type &;
	using const_reference    = 	const value_type &;
	using size_type          = 	std::size_t;
	using pointer 			 = 	value_type *;
	using const_pointer 	 = 	const value_type *;
	using node_type			 =	Node<T>;
	using node_pointer 		 =  node_type *;
	using const_node_pointer =	const  node_type *;


public:

	BinarySearchTree() = default;
	BinarySearchTree(std::initializer_list<T>);

	virtual ~BinarySearchTree() = default;

public:

	void 	_insert(const_reference value, node_pointer& root, node_pointer p = nullptr) override;

};


#include "bstree.hpp"


}
#endif
