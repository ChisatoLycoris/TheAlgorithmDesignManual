#pragma once

template<typename T>
class LinkedList {
private:
	class Node;
	int itemQty;
	Node* sentinel;
	class Node {
	public:
		T item;
		Node* prev;
		Node* next;
		Node();
		Node(T item, Node* prev, Node* next);
	};
public:
	class Iterator;
	LinkedList();
	~LinkedList();
	int size() const;
	void insert(T item);
	bool remove(T item);
	bool contains(T item) const;
	Iterator begin();
	Iterator end();
	class Iterator{
	private:
		Node* node;
	public:
		Iterator() {
			this->node = sentinel;
		}
		Iterator(Node* node) {
			this->node = node;
		}
		Iterator& operator=(Node* node) {
			this->node = node;
			return *this;
		}
		Iterator& operator++() {
			if (node) {
				this->node = node->next;
			}
			return *this;
		};
		Iterator operator++(int) {
			Iterator iterator = *this;
			++*this;
			return iterator;
		}
		bool operator!=(const Iterator& iterator) {
			return this->node != iterator.node;
		}
		T operator*() {
			return node->item;
		}
	};
};

template<typename T>
LinkedList<T>::Node::Node() {
	item = T();
	prev = this;
	next = this;
}

template<typename T>
LinkedList<T>::Node::Node(T item, Node* prev, Node* next) {
	this->item = item;
	this->prev = prev;
	this->next = next;
}

template<typename T>
LinkedList<T>::LinkedList() {
	itemQty = 0;
	sentinel = new Node();
}

template<typename T>
LinkedList<T>::~LinkedList() {
	for (Node* temp = sentinel; itemQty >= 0; itemQty--) {
		Node* currentNode = temp;
		temp = temp->next;
		delete currentNode;
	}
}

template<typename T>
int LinkedList<T>::size() const {
	return itemQty;
}

template<typename T>
void LinkedList<T>::insert(T item) {
	Node* newNode = new Node(item, sentinel->prev, sentinel);
	sentinel->prev->next = newNode;
	sentinel->prev = newNode;
	itemQty += 1;
}

template<typename T>
bool LinkedList<T>::remove(T item) {
	Node* temp = sentinel->next;
	for (int i = 0; i < itemQty; i++) {
		if (temp->item != item) {
			temp = temp->next;
			continue;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
		itemQty -= 1;
		return true;
	}
	return false;
}

template<typename T>
bool LinkedList<T>::contains(T item) const {
	Node* temp = sentinel->next;
	for (int i = 0; i < size; i++) {
		if (temp->item == item) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}

template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::begin()
{
	return Iterator(sentinel->next);
}

template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end()
{
	return Iterator(sentinel);
}

