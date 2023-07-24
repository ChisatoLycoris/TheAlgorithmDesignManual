#pragma once
#include "Deque.h"

template<class T>
class LinkedListDeque : public Deque<T>
{
	class Node
	{
	public:
		T* item;
		Node* prev;
		Node* next;
		Node();
		Node(T item, Node* prev, Node* next);
	};
	int listSize;
	Node* sentinel;
public:
	LinkedListDeque();
	int size() const override;
	void addFirst(T item) override;
	void addLast(T item) override;
	void printDeque() const override;
	T removeFirst() override;
	T removeLast() override;
	T get(int index) const override;
};
