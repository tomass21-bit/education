#pragma once
#include "shape.h"

class Line: public Shape {
public:
	Line(int _x1, int _y1, int _x2, int _y2);
	virtual void shift(int m,int n);
	virtual void scaleX(int a);
	virtual void scaleY(int d);
	virtual void scale(int s);
protected:
	int x1 = 0, y1 = 0;
	int x2 = 0, y2 = 0;
	double square=0;
	double volume = 0;
};


