#pragma once
#include "PriorityQueue.h"

template<typename K, typename V>
class PriorityQueueHeapImpl : public PriorityQueue<K, V> {
private:
	int itemQty;
	int arrayLength;
	K* keys;
	V* values;
	void resizeToBigger();
	void resizeToSmaller();
	void resize(int newSize);
	void swim(int k);
	void sink(int k);
	void swap(int a, int b);
public:
	PriorityQueueHeapImpl();
	~PriorityQueueHeapImpl();
	int size() const override;
	void put(const K& key, const V& value) override;
	V removeSmallest() override;
	V getSmallest() const override;
};

template<typename K, typename V>
inline void PriorityQueueHeapImpl<K, V>::resizeToBigger() {
	double usage = itemQty / (double)arrayLength;
	if (usage > 0.8) {
		resize(arrayLength * 2);
	}
}

template<typename K, typename V>
inline void PriorityQueueHeapImpl<K, V>::resizeToSmaller() {
	double usage = itemQty / (double)arrayLength;
	if (usage < 0.3 && arrayLength > 15) {
		resize(arrayLength / 2);
	}
}

template<typename K, typename V>
inline void PriorityQueueHeapImpl<K, V>::resize(int newSize) {
	K* newKeys = new K[newSize];
	V* newValues = new V[newSize];
	for (int i = 1; i <= itemQty; i++) {
		newKeys[i] = keys[i];
		newValues[i] = values[i];
	}
	delete keys;
	delete values;
	keys = newKeys;
	values = newValues;
	arrayLength = newSize;
}

template<typename K, typename V>
inline void PriorityQueueHeapImpl<K, V>::swim(int k) {
	int parent = k / 2;
	if (keys[parent] > keys[k] && parent > 0) {
		swap(parent, k);
		swim(parent);
	}
}

template<typename K, typename V>
inline void PriorityQueueHeapImpl<K, V>::sink(int k) {
	int leftChild = 2 * k;
	int rightChild = 2 * k + 1;
	bool leftIsSmaller = leftChild < itemQty && keys[leftChild] < keys[k];
	bool rightIsSmaller = rightChild < itemQty && keys[rightChild] < keys[k];
	if (leftIsSmaller && rightIsSmaller) {
		int smaller = keys[leftChild] < keys[rightChild]
			? leftChild
			: rightChild;
		sink(smaller);
		return;
	}
	if (leftIsSmaller) {
		sink(leftChild);
	}
	if (rightIsSmaller) {
		sink(rightChild);
	}
}

template<typename K, typename V>
inline void PriorityQueueHeapImpl<K, V>::swap(int a, int b) {
	K tempKey = keys[a];
	keys[a] = keys[b];
	keys[b] = tempKey;
	V tempValue = values[a];
	values[a] = values[b];
	values[b] = tempValue;
}

template<typename K, typename V>
inline PriorityQueueHeapImpl<K, V>::PriorityQueueHeapImpl() {
	itemQty = 0;
	arrayLength = 8;
	keys = new K[arrayLength];
	values = new V[arrayLength];
}

template<typename K, typename V>
inline PriorityQueueHeapImpl<K, V>::~PriorityQueueHeapImpl() {
	delete keys;
	delete values;
}

template<typename K, typename V>
inline int PriorityQueueHeapImpl<K, V>::size() const {
	return itemQty;
}

template<typename K, typename V>
inline void PriorityQueueHeapImpl<K, V>::put(const K& key, const V& value) {
	itemQty++;
	keys[itemQty] = key;
	values[itemQty] = value;
	swim(itemQty);
	resizeToBigger();
}

template<typename K, typename V>
inline V PriorityQueueHeapImpl<K, V>::removeSmallest()
{	
	V smallest = values[1];
	swap(1, itemQty);
	sink(1);
	itemQty--;
	return smallest;
}

template<typename K, typename V>
inline V PriorityQueueHeapImpl<K, V>::getSmallest() const
{
	return values[1];
}
