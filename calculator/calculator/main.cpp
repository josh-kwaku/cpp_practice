#include <iostream>

using namespace std;

double test(double, char, double);

int main() {
	cout << test(7, '+', 10);
}

double test(double number1, char operate, double number2) {
	auto add = [number1, number2]() { return number1 + number2; };
	auto subtract = [number1, number2]() { return number1 - number2; };
	auto multiply = [number1, number2]() { return number1 * number2; };
	auto divide = [number1, number2]() { return number1 / number2; };

	double result = 0;

	switch (operate) {
	case '+':
		result = add();
		break;
	case '-':
		result = subtract();
		break;
	case '*':
		result = multiply();
		break;
	case '/':
		result = divide();
		break;
	default:
		result = -1;
	}

	return result;
}