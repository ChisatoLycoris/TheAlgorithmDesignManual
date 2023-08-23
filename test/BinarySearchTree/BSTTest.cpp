#include "../pch.h"
#include "../../src/BinarySearchTree/BST.h"

TEST(LoopTest, BSTTest) {
	BST<int> bst;
	EXPECT_TRUE(bst.isEmpty());
	for (int i = 0; i < 100; i++) {
		bst.insertion(i);
		EXPECT_EQ(bst.size(), i + 1);
	}
	EXPECT_FALSE(bst.isEmpty());
	bst.printTree();
	for (int i = 0; i < 100; i++) {
		int j = 99 - i;
		bool b = 99 - i > 49;
		EXPECT_EQ(bst.search(j), b);
		EXPECT_EQ(bst.top(), i);
		bst.deletion(i);
		EXPECT_EQ(bst.size(), j);
	}
	EXPECT_TRUE(bst.isEmpty());
}