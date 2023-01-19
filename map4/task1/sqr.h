#pragma once
#include "line.h"
class Sqr: public Line {
public:
	Sqr(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4);
	 void shift(int m, int n)override;
	 void scaleX(int a)override;
	 void scaleY(int d)override;
	 void scale(int s)override;

protected:
	int
		x3 = 0, y3 = 0,
		x4 = 0, y4 = 0;
	int a;
	int b;
	double square;
	double volume = 0;
};