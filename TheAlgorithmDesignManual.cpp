// TheAlgorithmDesignManual.cpp : Defines the entry point for the application.
//

#include "TheAlgorithmDesignManual.h"
#include "src/BinarySearchTree/BST.h"

using namespace std;

int main()
{
	BST<int> bst;
	bst.insertion(7);
	bst.printTree();
	bst.insertion(7);
	bst.printTree();
	bst.insertion(3);
	bst.printTree();
	bst.insertion(5);
	bst.printTree();
	bst.insertion(2);
	bst.printTree();
	bst.insertion(9);
	bst.printTree();
	bst.insertion(6);
	bst.printTree();
	bst.insertion(4);
	bst.printTree();
	bst.insertion(8);
	bst.printTree();
	bst.insertion(10);
	bst.printTree();

}
