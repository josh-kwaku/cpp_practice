#include "BitArray.h"
#include <cmath>

BitArray::BitArray(int cap) : capacity(cap) {
	// size of bit array =  capacity / word size in machine since each index will contain "wordsize" number of bits
	word_size = 8 * sizeof(int); // in bits
	capacity = ceil(capacity / word_size);
	list = new int[capacity];
	initArray();
}

void BitArray::initArray() {
	for (int i = 0; i < capacity; i++)
	{
		list[i] = 0;
	}
}

void BitArray::add(int x) {
	int array_index = x / word_size;
	int bit_position = x % word_size;
	setBit(array_index, bit_position);
}

void BitArray::remove(int x) {
	int array_index = x / word_size;
	int bit_position = x % word_size;
	clearBit(array_index, bit_position);
}

bool BitArray::check(int x) {
	int array_index = x / word_size;
	int bit_position = x % word_size;
	return checkBit(array_index, bit_position);
}

void BitArray::setBit(int array_index, int bit_position) {
	unsigned int flag = 1; // unsigned because int is signed by default in c++
	flag = flag << bit_position; // place 1 in the desired bit position by doing a left shift "bit_position" times
	list[array_index] = list[array_index] | flag; // turn on the bit at that position using the bitwise OR operator;
}

void BitArray::clearBit(int array_index, int bit_position) {
	unsigned int flag = 1; // unsigned because int is signed by default in c++
	flag = flag << bit_position; // place 1 in the desired bit position by doing a left shift "bit_position" times
	flag = ~flag;
	list[array_index] = list[array_index] & flag; // turn on the bit at that position using the bitwise OR operator;
}

bool BitArray::checkBit(int array_index, int bit_position) {
	unsigned int flag = 1; // unsigned because int is signed by default in c++
	flag = flag << bit_position; // place 1 in the desired bit position by doing a left shift "bit_position" times
	if (list[array_index] & flag) // if the result is non-zero, then the bit at "bit_position" is set
		return 1;
	else
		return 0;
}

int& BitArray::operator[](int i) {
	return list[i];
}

BitArray::~BitArray() {
	delete[] list;
}