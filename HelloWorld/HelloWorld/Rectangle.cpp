#include "Rectangle.h";

Rectangle::Rectangle() {
	height = 0;
	length = 0;
}

void Rectangle::setHeight(int height) {
	this->height = height;
}

void Rectangle::setLength(int length) {
	this->length = length;
}

float Rectangle::area() {
	return length * height;
}

float Rectangle::perimiter() {
	return 2 * (length + height);
}