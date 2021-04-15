#include <iostream>
#include <cmath>
#include <functional>
#include <string>
#include "Rectangle.h"

#define PI 3.1416
using namespace std;

struct test {
	int x, y;

	int* GetPosition() {
		return &x;
	}
};

union Value {
	int i;
	double d;
};

class Sphere {
private:
	const double density;
	double radius;
public:
	Sphere(double r) : radius(r), density(4.3) { // member initialization lists
	}

	double volume() {
		return 4 * PI * radius * radius * radius / 3;
	}

	double mass() {
		return density * volume();
	}
};

// constructor delegation
class Collector {
private:
	int size;
	int capacity;
	int* list;

public:
	Collector() : Collector(0) {};
	Collector(int cap) : capacity(cap), size(0) {
		if (cap > 0) {
			list = new int[cap];
		}
		else
			capacity = 0;
	}

	bool append(int v) {
		if (size < capacity) {
			list[size++] = v;
			return true;
		}
		else
			return false;
	}

	int getCapacity() {
		return capacity;
	}

	friend void reset(Collector& c);

	~Collector() {
		if (size > 0) {
			delete[] list;
		}
	}
};

// friend function
void reset(Collector& c) {
	c.capacity = 0;
	c.list = new int[c.capacity];
	c.size = 0;
}

//class Rectangle {
//private:
//	float length;
//	float height;
//
//public:
//	Rectangle() {
//		length = 0;
//		height = 0;
//	}
//
//	void setLength(float length) {
//		this->length = length;
//	}
//
//	void setHeight(float height) {
//		this->height = height;
//	}
//
//	float perimiter() {
//		return 2 * (length + height);
//	}
//
//	float area() {
//		return length * height;
//	}
//};

int main()
{
	Sphere s(3.2);
	cout << "Volume: " << s.volume() << ", mass: " << s.mass();

	// A uselsess collector object of 0 capacity
	Collector c1;
	// Another collector object with capacity of 10
	Collector c2(10);
	cout << "Cap: " << c2.getCapacity() << endl;
	for (size_t i = 0; i < 15; i++)
	{
		cout << c2.append(i) << endl;
	}
	reset(c2);
	cout << "Cap2: " << c2.getCapacity() << endl;

	test t = { 4,5 };
	// create an array with the values in t without all the copying and all using type punning;
	int* position = t.GetPosition();
	int y[2] = { *position, *(position + 1) };
	for (int i = 0; i < 2; i++) {
		cout << y[i] << " ";
	}

	Value v = { 123 };
	v.d = 90;
	cout << endl << v.i << ", " << v.d << endl;

	Rectangle rec;
	rec.setHeight(10);
	rec.setLength(23);
	cout << "Area = " << rec.area() << endl;
	cout << "Perimiter = " << rec.perimiter() << endl;
	cout << sizeof(size_t) << endl;
}