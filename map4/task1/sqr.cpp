#include "sqr.h"
Sqr::Sqr(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4) :Line(_x1, _y1, _x2, _y2) {
	x3 = _x3;
	y3 = _y3;
	x4 = _x4;
	y4 = _y4;

	 a = abs(x1 - x2);
	 b = abs(y1 - y2);
	square = a * b;
}
void Sqr::shift(int m, int n) {
	x1 += m; y1 += n;
	x2 += m; y2 += n;
	x3 += m; y3 += n;
	x4 += m; y4 += n;
	
}
void Sqr::scaleX(int a) {
	x1 *= a;
	x2 *= a;
	x3 *= a;
	x4 *= a;
}
void Sqr::scaleY(int d) {
	y1 *= d;
	y2 *= d;
	y3 *= d;
	y4 *= d;
}
void Sqr::scale(int s) {
	x1 /= s; y1 /= s;
	x2 /= s; y2 /= s;
	x3 /= s; y3 /= s;
	x4 /= s; y4 /= s;
}
