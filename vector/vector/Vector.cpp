//#include "Vector.h"
//#include <stdexcept>
//
//Vector::Vector(int sz) {
//	if (sz < 0)
//		throw std::length_error{ "Vector Constructor: negative size" };
//	elem = new double[sz];
//	size = sz;
//} // construct a vector
//
//Vector::Vector(std::initializer_list<double> lst)
//	: elem{ new double[lst.size()] }, size{ static_cast<int>(lst.size()) } {
//	std::copy(lst.begin(), lst.end(), elem);
//}
//
//double& Vector::operator[](int i) { // element access - overriding the [] operator
//	if (i < 0 || size <= i)
//		throw std::out_of_range{ "Vector::Operator[]" };
//	return elem[i];
//}
//
//int Vector::length() {
//	return size;
//}
//
//Vector::~Vector() {
//	delete[] elem;
//}
//
////void push_back(double x) {
//	//return;
////}