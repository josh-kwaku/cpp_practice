#include <iostream>
using namespace std;

bool isPalindrome(int number);

int main() {
	int num = 2102;

	isPalindrome(num) ? cout << "Palindrome" : cout << "Not palindrome";
}

bool isPalindrome(int number) {
	int temp = number;
	int reverse = 0;
	int remainder = 0;
	
	/*
	* a number is a  palindrome if it is equal to it's reverse
	* to get it's reverse, continuosly get it's last digit and add it to the previosuly added digits * 10
	*/
	while (temp != 0) {
		remainder = temp % 10;
		reverse = reverse * 10 + remainder;
		temp = temp / 10; // remove last digit
	}

	return reverse == number;
}