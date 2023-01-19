#pragma once
#include "circle.h"

class Cylinder :public Circle {
	Cylinder(int _x1, int _y1, double R, double H);
	double volume;
	double height;
	double square;

};