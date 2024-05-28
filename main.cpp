#include <iostream>
#include "bstree.h"
#include "red_black_tree.h"

using std::cout, std::endl, cocobolo::Node, cocobolo::RBnode, cocobolo::RedBlackTree, cocobolo::BinarySearchTree;

// cocobolo::Tree<int> tree = {300, 200, 100, 120, 140, 130, 135, 132, 133};
//cocobolo::Tree<int> tree = {64, 20, 40, 15, 17, 16, 35, 37, 50, 100, 101, 67, 66, 70};

int main()
{
	RedBlackTree<int, std::greater<int>> tree = {8, 5, 15, 12, 19, 23, 9, 13, 10};

	// tree.rrotate( tree.find(15) );

	tree.postorder([](const RBnode<int> *root){

		std::string col = (root->m_color == cocobolo::__color::RED) ? "RED" : "BLACK";

		if (root->parent == nullptr)
				std::cout << root->m_data << " : " << col  << " : Parent -> X" << std::endl;
		else
			std::cout << root->m_data << " : " << col  << " : Parent -> " << root->parent->m_data << std::endl;

	});


	// tree.inorder([](const RBnode<int> *root){if (root->parent) cout << root->m_data << " : " << root->parent->m_data << endl;});
	// tree.inorder([](const RBnode<int> *root){cout << root->m_data << endl;});

	// std::cout << tree.successor(135)->get_value() << std::endl;
}
