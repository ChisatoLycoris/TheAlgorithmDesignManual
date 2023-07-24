#include <iostream>
#include <stdexcept>
#include "LinkedListDeque.h"

template<class T>
LinkedListDeque<T>::Node::Node()
{
	item = nullptr;
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
	listSize = 0;
	sentinel = new Node();
}

template<class T>
int LinkedListDeque<T>::size() const
{
	return listSize;
}

template<class T>
void LinkedListDeque<T>::addFirst(T item)
{
	Node* newNode = new Node(item, sentinel, sentinel->next);
	sentinel->next->prev = newNode;
	sentinel->next = newNode;
	listSize += 1;
}

template<class T>
void LinkedListDeque<T>::addLast(T item)
{
	Node* newNode = new Node(item, sentinel->prev, sentinel);
	sentinel->prev->next = newNode;
	sentinel->prev = newNode;
	listSize += 1;
}

template<class T>
void LinkedListDeque<T>::printDeque() const 
{
	Node* temp = sentinel->next;
	while (temp != sentinel)
	{
		std::cout << temp->item << " ";
	}
	std::cout << std::endl;
}

template<class T>
T LinkedListDeque<T>::removeFirst()
{
	if (listSize = 0)
	{
		throw std::invalid_argument("Call removeFirst() with size 0.");
	}
	Node* first = sentinel->next;
	sentinel->next = sentinel->next->next;
	T item = first->item;
	delete first;
	listSize -= 1;
	return item;
}

template<class T>
T LinkedListDeque<T>::removeLast()
{	
	if (listSize = 0)
	{
		throw std::invalid_argument("Call removeLast() with size 0.");
	}
	Node* last = sentinel->prev;
	sentinel->prev = sentinel->prev->prev;
	T item = last->item;
	delete last;
	listSize -= 1;
	return item;
}

template<class T>
T LinkedListDeque<T>::get(int index) const 
{
	if (index < 0 || index >= listSize)
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
