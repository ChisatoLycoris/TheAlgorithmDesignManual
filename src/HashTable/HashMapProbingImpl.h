#pragma once
#include "HashMap.h"
#include <functional>
#include <stdexcept>

template<typename K, typename V>
class HashMapProbingImpl : public HashMap<K, V> {
private:
	int itemQty;
	int arrayLength;
	K* keys;
	V* values;
	void resizeToBigger();
	void resizeToSmaller();
	void resize(int newSize);
	int quadricProbing(int hash, int i) const;
	int findIndex(const K& key) const;
public: 
	HashMapProbingImpl();
	~HashMapProbingImpl();
	int size() const override;
	void insert(const K& key, const V& value) override;
	void remove(const K& key) override;
	V get(const K& key) const override;
};

template<typename K, typename V>
inline void HashMapProbingImpl<K, V>::resizeToBigger() {
	double usage = itemQty / (double)arrayLength;
	if (usage > 0.6) {
		resize(arrayLength * 2);
	}
}

template<typename K, typename V>
inline void HashMapProbingImpl<K, V>::resizeToSmaller() {
	double usage = itemQty / (double)arrayLength;
	if (usage < 0.2 && itemQty > 8) {
		resize(arrayLength / 2);
	} else {
		resize(arrayLength);
	}
}

template<typename K, typename V>
inline void HashMapProbingImpl<K, V>::resize(int newSize) {
	int originalArrayLength = arrayLength;
	arrayLength = newSize;
	K* originalKeys = keys;
	V* originalValues = values;
	itemQty = 0;
	keys = new K [arrayLength]();
	values = new V [arrayLength]();
	for (int i = 0; i < originalArrayLength; i++) {
		if (originalKeys[i] == K()) continue;
		insert(originalKeys[i], originalValues[i]);
	}
}

template<typename K, typename V>
inline int HashMapProbingImpl<K, V>::quadricProbing(int hash, int i) const {
	return (int)(hash + 0.5 * i + 0.5 * i * i) % arrayLength;
}

template<typename K, typename V>
inline int HashMapProbingImpl<K, V>::findIndex(const K& key) const {
	int hash = std::hash<K>() (key);
	hash = std::abs(hash);
	bool isSearching = true;
	int i = 0;
	while (isSearching) {
		int index = quadricProbing(hash, i);
		if (keys[index] == K() || keys[index] == key) {
			isSearching = false;
			return index;
		}
		i++;
	}
	return -1;
}

template<typename K, typename V>
inline HashMapProbingImpl<K, V>::HashMapProbingImpl() {
	itemQty = 0;
	arrayLength = 8;
	keys = new K[arrayLength]();
	values = new V[arrayLength]();
}

template<typename K, typename V>
inline HashMapProbingImpl<K, V>::~HashMapProbingImpl() {
	delete keys;
	delete values;
}

template<typename K, typename V>
inline int HashMapProbingImpl<K, V>::size() const {
	return itemQty;
}

template<typename K, typename V>
inline void HashMapProbingImpl<K, V>::insert(const K& key, const V& value) {
	int index = findIndex(key);
	if (keys[index] == K()) {
		keys[index] = key;
		values[index] = value;
		itemQty++;
	} else {
		values[index] = value;
	}
	resizeToBigger();
}

template<typename K, typename V>
inline void HashMapProbingImpl<K, V>::remove(const K& key) {
	int index = findIndex(key);
	if (keys[index] != K()) {
		keys[index] = K();
		values[index] = V();
		itemQty--;
		resizeToSmaller();
	}
}

template<typename K, typename V>
inline V HashMapProbingImpl<K, V>::get(const K& key) const
{
	int index = findIndex(key);
	if (keys[index] != K()) {
		return values[index];
	}
	return V();
	// throw std::invalid_argument("call get with not exist key");
}
