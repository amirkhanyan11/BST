#include <iostream>
#include "bstree.h"
#include "red_black_tree.h"

using std::cout, std::endl, cocobolo::Node, cocobolo::RBnode, cocobolo::RedBlackTree, cocobolo::BinarySearchTree;

// cocobolo::Tree<int> tree = {300, 200, 100, 120, 140, 130, 135, 132, 133};
//cocobolo::Tree<int> tree = {64, 20, 40, 15, 17, 16, 35, 37, 50, 100, 101, 67, 66, 70};

int main()
{
	RedBlackTree<int> tree = {15, 8, 17};

	tree.postorder([](const RBnode<int> *root){

		std::string col = (root->m_color == cocobolo::__color::RED) ? "RED" : "BLACK";
		cout << root->m_data << " : " << col << endl;

	});

	// tree.inorder([](const RBnode<int> *root){if (root->parent) cout << root->m_data << " : " << root->parent->m_data << endl;});
	// tree.inorder([](const RBnode<int> *root){cout << root->m_data << endl;});

	// std::cout << tree.successor(135)->get_value() << std::endl;
}
