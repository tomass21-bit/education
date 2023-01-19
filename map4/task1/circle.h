#define _USE_MATH_DEFINES
#pragma once
#include "Shape.h"
class Circle :public Shape {
public:
	Circle(int _x1, int _y1, double R);
	
protected:
	

	double radius;
	double square;
	double volume = 0;
};
