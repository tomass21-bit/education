#include "cylinder.h"
Cylinder::Cylinder(int _x1, int _y1, double R, double H) :Circle(_x1, _y1, R) {
	height=H;
	square = M_PI * R * R + 2 * R * height;
	volume = M_PI * R * R * height;
};