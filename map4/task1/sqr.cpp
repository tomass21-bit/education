#include "sqr.h"
Sqr::Sqr(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4) :Line(_x1, _y1, _x2, _y2) {
	x3 = _x3;
	y3 = _y3;
	x4 = _x4;
	y4 = _y4;

	int a = abs(x1 - x2);
	int b = abs(y1 - y2);
	square = a * b;
}
