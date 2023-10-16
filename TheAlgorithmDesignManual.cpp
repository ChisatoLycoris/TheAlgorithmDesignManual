// TheAlgorithmDesignManual.cpp : Defines the entry point for the application.

#include <iostream>
#include "TheAlgorithmDesignManual.h"
#include "src/PriorityQueue/PriorityQueueHeapImpl.h"

using namespace std;

class temp {
public:
	int a;
	temp(int a) {
		this->a = a;
	}
	temp() {
		this->a = 0;
	}
};

int main()
{
	PriorityQueueHeapImpl<int, temp> pq;
	pq.put(8, temp(-8));
	pq.put(7, temp(-7));
	pq.put(6, temp(-6));
	pq.put(5, temp(-5));
	pq.put(4, temp(-4));
	pq.put(1, temp(-8));
	pq.put(3, temp(-3));
	pq.put(2, temp(-2));
	pq.put(1, temp(-1));

	return 0;
}
