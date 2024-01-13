#include <iostream>
#include "bstree.h"


int main()
{
	juju::Tree<int> tree;
	tree.insert(64);
	tree.insert(20);
	tree.insert(100);
	tree.insert(67);
	tree.insert(101);
	tree.insert(70);
	tree.insert(66);
	tree.insert(15);
	tree.insert(40);
	tree.insert(35);
	tree.insert(50);
	tree.insert(17);


	tree.inorder();
	std::cout << std::endl;
	tree.remove(20);
	std::cout << std::endl;
	tree.inorder();
}
