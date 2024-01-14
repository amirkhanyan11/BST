#include <iostream>
#include "bstree.h"


int main()
{
	juju::Tree<int> tree = {300, 200, 100, 120, 140, 130, 135, 132, 133};

	//std::cout << tree.successor(135)->m_data << std::endl;
	tree.inorder();
}
