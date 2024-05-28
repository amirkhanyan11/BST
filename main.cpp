#include <iostream>
#include "bstree.h"
#include "red_black_tree.h"

using std::cout,
	  std::cin,
	  std::endl,
	  cocobolo::Node,
	  cocobolo::RBnode,
	  cocobolo::RedBlackTree,
	  cocobolo::BinarySearchTree;

// cocobolo::Tree<int> tree = {300, 200, 100, 120, 140, 130, 135, 132, 133};
//cocobolo::Tree<int> tree = {64, 20, 40, 15, 17, 16, 35, 37, 50, 100, 101, 67, 66, 70};

int main()
{
	RedBlackTree<int> tree = {1, 2, 3, 4, 5};

	tree.remove(2);

	// int x = 0;

	// cin >> x;

	// RedBlackTree<int> tree;


	// while (x != 666)
	// {
	// 	tree.insert(x);

		tree.preorder([](const RBnode<int> *root){

			std::string col = (root->m_color == cocobolo::__color::RED) ? "RED" : "BLACK";

			std::string childof;
			if (root->parent == nullptr) childof = " Root";

			else if (root->parent->left == root) childof = "Left child of ";

			else if (root->parent->right == root) childof = "Right child of ";

			if (root->parent == nullptr)
					std::cout << root->m_data << " : " << col <<  " : " << childof << std::endl;
			else
				std::cout << root->m_data << " : " << col << " : " << childof << root->parent->m_data << std::endl;

		});
	// 	cin >> x;
	// }

}
