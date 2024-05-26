#include <iostream>
#include "bstree.h"

using std::cout, std::endl, juju::Node, juju::BinarySearchTree;

// juju::Tree<int> tree = {300, 200, 100, 120, 140, 130, 135, 132, 133};
//juju::Tree<int> tree = {64, 20, 40, 15, 17, 16, 35, 37, 50, 100, 101, 67, 66, 70};

int main()
{
	BinarySearchTree<int> tree = {5, 2, 10, 8, 6, 9, 12};


	// tree.inorder([](const Node<int> *root){if (root->parent) cout << root->m_data << " : " << root->parent->m_data << endl;});


	// std::cout << tree.successor(135)->get_value() << std::endl;
}
