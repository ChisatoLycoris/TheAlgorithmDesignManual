#include "../pch.h"
#include "../../src/Deque/ArrayDeque.h"

TEST(LoopAddFirst, ArrayDequeTest) {
	Deque<int>* deque = new ArrayDeque<int>();
	for (int i = 0; i < 100; i++) {
		deque->addFirst(i);
		EXPECT_EQ(deque->size(), i + 1);
	}
	for (int i = 0; i < 100; i++) {
		EXPECT_EQ(deque->get(i), 99 - i);
	}
}