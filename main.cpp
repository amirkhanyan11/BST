#include <iostream>
#include "bstree.h"


int main()
{
	juju::Tree<int> tree = {64, 20, 100, 15, 40, 35, 50, 17};

	tree.remove(20);
	tree.inorder();
	std::cout << std::endl;
	//tree.clear();

}
