#include <iostream>
#include "HashMap.h"

using namespace std;


int main() {
	MyHashMap<char, int> m;

	m['a'] = 90;
	m['b'] = 20;
	m['c'] = 30;
	m['d'] = 70;
	m['e'] = 90;
	m['f'] = 30;
	m.remove('d');;

}