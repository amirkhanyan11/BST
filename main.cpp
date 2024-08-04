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
	RedBlackTree<int> tree = {1, 2, 3, 4, 5, 6, 7, 8};
	// RedBlackTree<int> tree = {};

	// tree.insert(1);

	tree.preorder([](const RBnode<int> *root) {

		cout << root->val << "  ";
	});
	cout << endl;

	return 0;
}
