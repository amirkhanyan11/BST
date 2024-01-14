#ifndef __BSTREE__
#define __BSTREE__
#include <iostream>

namespace juju
{

	template <typename T>
	class Tree
	{

	public:

		Tree(std::initializer_list<T>);
		Tree() = default;
		~Tree();


	private:

		struct Node
		{

		public:

			friend class Tree;
			Node(const T&);
			Node& operator=(Node&& other);

			void display() const noexcept;

		private:
		
			T m_data = T{};
			Node* left{nullptr};
			Node* right{nullptr};
		};

		Node* m_root = nullptr;


		void _insert(const T& value, Node*& root);
		Node* _search(const T& value, Node* root) const noexcept;

		void _inorder(const Node*) const noexcept;
		void _preorder(const Node*) const noexcept;
		void _postorder(const Node*) const noexcept;
		Node const* _find_min(Node const*) const noexcept;
		Node const* _find_max(Node const*) const noexcept;
		Node* _predecessor(Node*) noexcept;
		Node* _successor(Node*) noexcept;
		size_t _childcount(Node*) const noexcept;
		Node* _parent(Node*, Node*) const noexcept;
		void _remove(Node*, Node*, const size_t) noexcept;
		void _clear(Node*) noexcept;
		size_t _size(Node const*) const noexcept;
		size_t _height(Node const*) const noexcept;


	public:

		void insert(const T& value);
		void remove(const T& value) noexcept;
		Node* search(const T& value) const noexcept;
		void inorder() const noexcept;
		void postorder() const noexcept;
		void preorder() const noexcept;
		Node* find_min() noexcept;
		Node* find_max() noexcept;
		Node const* find_min() const noexcept;
		Node const* find_max() const noexcept;
		Node* predecessor(const T&) noexcept;
		Node* successor(const T&) noexcept;
		size_t size() const noexcept;
		size_t height() const noexcept;
	};


}


#include "bstree.hpp"

#endif
