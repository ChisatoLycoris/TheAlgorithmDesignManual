// TheAlgorithmDesignManual.cpp : Defines the entry point for the application.

#include "TheAlgorithmDesignManual.h"
#include "src/HashTable/HashMapProbingImpl.h"

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
	HashMapProbingImpl<int, temp> map;
	
	map.insert(1, temp(-1));
	map.insert(2, temp(-2));
	map.insert(3, temp(-3));
	map.insert(4, temp(-4));
	map.insert(5, temp(-5));
	map.insert(6, temp(-6));
	for (int i = 1; i < 7; i++) {
		cout << map.get(i).a << " ";
	}
	
	cout << endl;
	return 0;
}
