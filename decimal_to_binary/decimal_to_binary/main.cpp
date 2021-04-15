#include <iostream>
using namespace std;

int convert(int number);

int main() {
	int number = 15;
	cout << convert(number);
}

int convert(int number) {
	int remainder, product = 1;
	int binary = 0;
	while (number != 0) {
		remainder = number % 2;
		binary += remainder * product;
		number /= 2;
		product *= 10;
	}
	return binary;
}