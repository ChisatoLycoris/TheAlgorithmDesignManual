#pragma once
#include <iostream>
#include <stdexcept>
#include "Deque.h"

template<class T>
class LinkedListDeque : public Deque<T>
{
	class Node
	{
	public:
		T item;
		Node* prev;
		Node* next;
		Node();
		Node(T item, Node* prev, Node* next);
	};
	int itemQty;
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

template<class T>
LinkedListDeque<T>::Node::Node()
{
	item = NULL;
	prev = this;
	next = this;
}

template<class T>
LinkedListDeque<T>::Node::Node(T item, Node* prev, Node* next)
{
	this->item = item;
	this->prev = prev;
	this->next = next;
}

template<class T>
LinkedListDeque<T>::LinkedListDeque()
{
	itemQty = 0;
	sentinel = new Node();
}

template<class T>
int LinkedListDeque<T>::size() const
{
	return itemQty;
}

template<class T>
void LinkedListDeque<T>::addFirst(T item)
{
	Node* newNode = new Node(item, sentinel, sentinel->next);
	sentinel->next->prev = newNode;
	sentinel->next = newNode;
	itemQty += 1;
}

template<class T>
void LinkedListDeque<T>::addLast(T item)
{
	Node* newNode = new Node(item, sentinel->prev, sentinel);
	sentinel->prev->next = newNode;
	sentinel->prev = newNode;
	itemQty += 1;
}

template<class T>
void LinkedListDeque<T>::printDeque() const
{
	Node* temp = sentinel->next;
	while (temp != sentinel)
	{
		std::cout << temp->item << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

template<class T>
T LinkedListDeque<T>::removeFirst()
{
	if (itemQty == 0)
	{
		throw std::invalid_argument("Call removeFirst() with size 0.");
	}
	Node* first = sentinel->next;
	sentinel->next = sentinel->next->next;
	sentinel->next->prev = sentinel;
	T item = first->item;
	delete first;
	itemQty -= 1;
	return item;
}

template<class T>
T LinkedListDeque<T>::removeLast()
{
	if (itemQty == 0)
	{
		throw std::invalid_argument("Call removeLast() with size 0.");
	}
	Node* last = sentinel->prev;
	sentinel->prev = sentinel->prev->prev;
	sentinel->prev->next = sentinel;
	T item = last->item;
	delete last;
	itemQty -= 1;
	return item;
}

template<class T>
T LinkedListDeque<T>::get(int index) const
{
	if (index < 0 || index >= itemQty)
	{
		throw std::out_of_range("Index out of bounds of the deque.");
	}
	Node* temp = sentinel->next;
	while (index != 0)
	{
		temp = temp->next;
		index -= 1;
	}
	return temp->item;
}