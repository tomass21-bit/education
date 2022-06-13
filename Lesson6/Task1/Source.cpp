#include <iostream>
#include "Header.h" 
void summ(int a, int b) {
	std::cout << a << " плюс " << b << " = " << a + b << std::endl;

}


void minus(int a, int b) {
	std::cout << a << " минус " << b << " = " << a - b << std::endl;

}
void times(int a, int b) {
	std::cout << a << " умножить " << b << " = " << a * b << std::endl;

}

void dev(int a, int b) {
	std::cout << a << " делить " << b << " = " << a / b << std::endl;

}

void abs(int a, int b) {
	long int c=1;
	for (int i = 0; i < b; ++i) {
		if (b == 0) {
			c = 1;
		}
		else if (b == 1) {
			c = a;
		}
		else
			c = c * a;
		
	}
	std::cout << a << " в степени  " << b << " = " << c  << std::endl;

}
