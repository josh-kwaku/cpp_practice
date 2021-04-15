#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H
class Rectangle {
	float length, height;

public:
	Rectangle();
	void setLength(int length);
	void setHeight(int height);
	float area();
	float perimiter();
};
#endif // !1