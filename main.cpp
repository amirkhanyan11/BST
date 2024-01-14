#include <iostream>
#include "bstree.h"


int main()
{
	juju::Tree<int> tree = {300, 200, 100, 120, 140, 130, 135, 132, 133};

	//juju::Tree<int> tree = {64, 20, 40, 15, 17, 16, 35, 37, 50, 100, 101, 67, 66, 70};


	std::cout << tree.height() << std::endl;
}
