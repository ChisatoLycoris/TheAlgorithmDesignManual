#include <iostream>
#include "LinkedListDeque.h"
#include "ArrayDeque.h"

int main()
{
	Deque<int>* deque = new ArrayDeque<int>();
	deque->addFirst(1);
	deque->printDeque();
	std::cout << "size: " << deque->size() << std::endl;
	deque->addFirst(2);
	deque->printDeque();
	std::cout << "size: " << deque->size() << std::endl;
	deque->addLast(3);
	deque->printDeque();
	std::cout << "size: " << deque->size() << std::endl;
	deque->addLast(4);
	deque->printDeque();
	std::cout << "size: " << deque->size() << std::endl;
	int remove1 = deque->removeFirst();
	deque->printDeque();
	std::cout << "size: " << deque->size() << std::endl;
	int remove2 = deque->removeLast();
	deque->printDeque();
	std::cout << "size: " << deque->size() << std::endl;

	std::cout << "remove1: " << remove1 << ", remove2: " << remove2 << std::endl;

	for (int i = 0; i < 100; i++)
	{
		deque->addLast(i);
	}
	deque->printDeque();
}

void codeStorage()
{
	Deque<int>* deque = new ArrayDeque<int>();
	deque->addFirst(1);
	deque->printDeque();
	std::cout << "size: " << deque->size() << std::endl;
	deque->addFirst(2);
	deque->printDeque();
	std::cout << "size: " << deque->size() << std::endl;
	deque->addLast(3);
	deque->printDeque();
	std::cout << "size: " << deque->size() << std::endl;
	deque->addLast(4);
	deque->printDeque();
	std::cout << "size: " << deque->size() << std::endl;
	int remove1 = deque->removeFirst();
	deque->printDeque();
	std::cout << "size: " << deque->size() << std::endl;
	int remove2 = deque->removeLast();
	deque->printDeque();
	std::cout << "size: " << deque->size() << std::endl;

	std::cout << "remove1: " << remove1 << ", remove2: " << remove2 << std::endl;
}
