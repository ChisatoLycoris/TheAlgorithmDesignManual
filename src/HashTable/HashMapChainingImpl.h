#pragma once
#include "HashMap.h"
#include "../Deque/LinkedList.h"
#include <functional>
#include <stdexcept>

template<typename K, typename V>
class HashMapChainingImpl : public HashMap<K, V> {
private:
	class Pair {
	public:
		K key;
		V value;
		Pair();
		Pair(K key, V value);
		~Pair();
		bool operator==(const Pair& p);
		bool operator!=(const Pair& p);
	};
	int itemQty;
	int arrayLength;
	LinkedList<Pair>** items;
	void resize();
	int getIndex(const K& key) const;
public:
	HashMapChainingImpl();
	~HashMapChainingImpl();
	int size() const override;
	void insert(const K& key, const V& value) override;
	void remove(const K& key) override;
	V get(const K& key) const override;
};

template<typename K, typename V>
inline HashMapChainingImpl<K, V>::Pair::Pair() {
	key = K();
	value = V();
}

template<typename K, typename V>
inline HashMapChainingImpl<K, V>::Pair::Pair(K key, V value) {
	this->key = key;
	this->value = value;
}

template<typename K, typename V>
inline HashMapChainingImpl<K, V>::Pair::~Pair() {}

template<typename K, typename V>
inline bool HashMapChainingImpl<K, V>::Pair::operator==(const Pair& p) {
	return this->key == p.key;
}

template<typename K, typename V>
inline bool HashMapChainingImpl<K, V>::Pair::operator!=(const Pair& p) {
	return this->key != p.key;
}

template<typename K, typename V>
inline void HashMapChainingImpl<K, V>::resize() {
	double usage = itemQty / (double)arrayLength;
	if ((usage >= 2 && usage <= 5)
			|| (usage < 2 && arrayLength < 16)) return;
	int originalArrayLength = arrayLength;
	arrayLength = usage < 2
		? arrayLength * 3 / 7
		: arrayLength * 7 / 3;
	LinkedList<Pair>** newItems = new LinkedList<Pair>*[arrayLength];
	for (int i = 0; i < arrayLength; i++) {
		newItems[i] = new LinkedList<Pair>();
	}
	for (int i = 0; i < originalArrayLength; i++) {
		LinkedList<Pair>* list = items[i];
		for (typename LinkedList<Pair>::Iterator it = list->begin();
				it != list->end(); it++) {
			Pair item = *it;
			int newIdx = getIndex(item.key);
			LinkedList<Pair>* newlist = newItems[newIdx];
			newlist->insert(item);
		}
		delete list;
	}
	delete items;
	items = newItems;
}

template<typename K, typename V>
inline int HashMapChainingImpl<K, V>::getIndex(const K& key) const
{
	int hash = std::hash<K>() (key);
	return std::abs(hash) % arrayLength;
}

template<typename K, typename V>
inline HashMapChainingImpl<K, V>::HashMapChainingImpl() {
	itemQty = 0;
	arrayLength = 13;
	items = new LinkedList<Pair>*[arrayLength];
	for (int i = 0; i < arrayLength; i++) { 
		items[i] = new LinkedList<Pair>();
	}
}

template<typename K, typename V>
inline HashMapChainingImpl<K, V>::~HashMapChainingImpl() {
	for (int i = 0; i < arrayLength; i++) {
		delete items[i];
	}
	delete items;
}

template<typename K, typename V>
inline int HashMapChainingImpl<K, V>::size() const {
	return itemQty;
}

template<typename K, typename V>
inline void HashMapChainingImpl<K, V>::insert(const K& key, const V& value) {
	Pair* item = new Pair(key, value);
	int idx = getIndex(key);
	LinkedList<Pair>* list = items[idx];
	if (!list->remove(*item)) {
		itemQty++;
	}
	list->insert(*item);
	resize();
}

template<typename K, typename V>
inline void HashMapChainingImpl<K, V>::remove(const K& key) {
	Pair* item = new Pair(key, 0);
	int idx = getIndex(key);
	LinkedList<Pair>* list = items[idx];
	if (list->remove(*item)) {
		itemQty--;
	}
	resize();
}

template<typename K, typename V>
inline V HashMapChainingImpl<K, V>::get(const K& key) const
{
	Pair* item = new Pair(key, 0);
	int idx = getIndex(key);
	LinkedList<Pair>* list = items[idx];
	for (typename LinkedList<Pair>::Iterator it = list->begin();
			it != list->end(); it++) {
		Pair current = *it;
		if (current == *item) {
			return current.value;
		}
	}
	throw std::invalid_argument("call get with not exist key");
}
