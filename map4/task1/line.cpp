#include "Line.h"
Line::Line(int _x1, int _y1, int _x2, int _y2 ) : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {};
 void Line::shift(int m, int n) {
	x1 += m; y1 += n;
	x2 += m; y2 += n;
}
 void Line::scaleX(int a) {
	 x1 *= a;
	 x2 *= a;
 }
 void Line::scaleY(int d ) {
	 y1 *= d;
	 y2 *= d;
 }
 void Line::scale(int s) {
	 x1 /= s; y1 /= s;
	 x2 /= s; y2 /= s;
 }
