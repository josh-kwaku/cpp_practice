#pragma once
#ifndef BitArray_H
#define BitArray_H

class BitArray
{
private:
	int size;
	int word_size;
	void setBit(int, int);
	bool checkBit(int, int);
	void clearBit(int, int);
	void initArray();
public:
	int capacity;
	int* list;
	BitArray(int);
	void add(int);
	void remove(int);
	bool check(int);
	int& operator[](int i);
	~BitArray();
};
#endif // !1
