// TheAlgorithmDesignManual.cpp : Defines the entry point for the application.
//

#include "TheAlgorithmDesignManual.h"
#include "src/Deque/LinkedListDeque.h"
#include "src/Deque/ArrayDeque.h"

using namespace std;

int main()
{
	Deque<int>* deque = new LinkedListDeque<int>();
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
	delete deque;
}
