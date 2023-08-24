// TheAlgorithmDesignManual.cpp : Defines the entry point for the application.
//

#include "TheAlgorithmDesignManual.h"
#include "src/BinarySearchTree/BST.h"

using namespace std;

int main()
{
	BST<int> bst;
	bst.insertion(7);
	bst.printAll();
	bst.insertion(7);
	bst.printAll();
	bst.insertion(3);
	bst.printAll();
	bst.insertion(5);
	bst.printAll();
	bst.insertion(2);
	bst.printAll();
	bst.insertion(9);
	bst.printAll();
	bst.insertion(6);
	bst.printAll();
	bst.insertion(4);
	bst.printAll();
	bst.insertion(8);
	bst.printAll();
	bst.insertion(10);
	bst.printAll();

}
