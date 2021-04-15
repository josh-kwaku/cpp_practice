#include <iostream>
//#include <stdexcept>
//#include "Vector.h"
//#include <vector>
//#include <iostream>
#include <bitset>

// use noexcept to mark a funtion as one that can't throw exceptions. If an exception eventually occurs, the program will terminate

//int& bad() {
//	int x = 90;
//
//	return x;
//}
//

int main() {

	//try {
	//	Vector v{ -90 };
	//	Vector vec{ 1,2,3,4,5 };
	//	//std::cout << vec.at(4);
	//}
	//catch (std::length_error& err) {
	//	std::cerr << err.what() << std::endl;
	//}
	//catch (std::bad_alloc& err) { // new didn't find any available memory to allocate
	//	std::cerr << err.what() << std::endl;
	//}
	//int l = bad();
	//std::cout << l << std::endl;
	std::bitset<64> b1("eat");
	std::cout << b1 << '\n';
}