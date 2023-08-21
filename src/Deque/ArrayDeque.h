#pragma once
#include <iostream>
#include <stdexcept>
#include "Deque.h"

template<class T>
class ArrayDeque : public Deque<T>
{
	int arrayLength;
	int itemQty;
	int startIndex;
	T* items;
	void resize();
	int convertIndex(int dequeIndex) const;
public:
	ArrayDeque();
	~ArrayDeque();
	int size() const override;
	void addFirst(T item) override;
	void addLast(T item) override;
	void printDeque() const override;
	T removeFirst() override;
	T removeLast() override;
	T get(int index) const override;
};

template<class T>
ArrayDeque<T>::ArrayDeque()
{
	arrayLength = 8;
	itemQty = 0;
	startIndex = 0;
	items = new T[arrayLength];
}

template<class T>
ArrayDeque<T>::~ArrayDeque()
{
	delete[] items;
}

template<class T>
int ArrayDeque<T>::size() const
{
	return itemQty;
}

template<class T>
void ArrayDeque<T>::addFirst(T item)
{
	resize();
	startIndex = startIndex > 0 ? (startIndex - 1) : (arrayLength - 1);
	items[startIndex] = item;
	itemQty += 1;
}

template<class T>
void ArrayDeque<T>::addLast(T item)
{
	resize();
	int lastIndex = convertIndex(itemQty);
	items[lastIndex] = item;
	itemQty += 1;
}

template<class T>
void ArrayDeque<T>::printDeque() const
{
	for (int i = 0; i < itemQty; i++)
	{
		int index = convertIndex(i);
		std::cout << items[index] << " ";
	}
	std::cout << std::endl;
}

template<class T>
T ArrayDeque<T>::removeFirst()
{
	if (itemQty == 0)
	{
		throw std::invalid_argument("Call removeFirst() with size 0.");
	}
	resize();
	T item = items[startIndex];
	startIndex = (startIndex >= arrayLength - 1) ? 0 : startIndex + 1;
	itemQty -= 1;
	return item;
}

template<class T>
inline T ArrayDeque<T>::removeLast()
{
	if (itemQty == 0)
	{
		throw std::invalid_argument("Call removeFirst() with size 0.");
	}
	resize();
	int lastIndex = convertIndex(itemQty - 1);
	T item = items[lastIndex];
	itemQty -= 1;
	return item;
}

template<class T>
T ArrayDeque<T>::get(int index) const
{
	if (index < 0 || index >= itemQty)
	{
		throw std::out_of_range("Index out of bounds of the deque.");
	}
	int dequeIndex = convertIndex(index);
	return items[dequeIndex];
}

template<class T>
void ArrayDeque<T>::resize()
{
	double usage = itemQty / (double)arrayLength;
	if ((usage >= 0.25 && usage <= 0.75) 
		|| (usage < 0.25 && arrayLength < 10)) return;
	int newArrayLength = (usage < 0.25) ?
		(arrayLength / 2) : (arrayLength * 2);
	T* newItems = new T[newArrayLength];
	for (int i = 0; i < itemQty; i++)
	{
		int index = convertIndex(i);
		newItems[i] = items[index];
	}
	delete[] items;
	items = newItems;
	arrayLength = newArrayLength;
	startIndex = 0;
}

template<class T>
int ArrayDeque<T>::convertIndex(int dequeIndex) const
{
	int index = startIndex + dequeIndex;
	if (index > arrayLength - 1)
	{
		index = index - arrayLength;
	}
	return index;
}
