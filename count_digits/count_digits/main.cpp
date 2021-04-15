/*
* Count the number of digits in a number
*/

#include <iostream>
#include <cmath>

using namespace std;

int count_digits(int);

int main() {
	int number = pow(2, 31) - 1;
	cout << count_digits(number);
}

int count_digits(int number) {
	if (number == 0) {
		return 0;
	}
	return 1 + count_digits(number / 10);
}