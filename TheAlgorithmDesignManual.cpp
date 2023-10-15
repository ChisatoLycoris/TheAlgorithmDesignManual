// TheAlgorithmDesignManual.cpp : Defines the entry point for the application.

#include "TheAlgorithmDesignManual.h"
#include "src/HashTable/HashMapChainingImpl.h"

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
	HashMapChainingImpl<int, temp> map;
	for (int i = 1; i < 100; i++) {
		map.insert(i, temp(i * -1));
	}
	
	map.insert(1, temp(1));
	map.insert(2, temp(2));
	map.insert(3, temp(3));
	for (int i = 1; i < 100; i++) {
		cout << map.get(i).a << " ";
	}
	
	cout << endl;
	return 0;
}
