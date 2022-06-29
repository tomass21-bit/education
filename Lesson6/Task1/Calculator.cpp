#include <iostream>
#include "Calculator.h" 
int summ(int a, int b) {
	return a + b ;

}


int minus(int a, int b) {
	return a - b ;

}
int times(int a, int b) {
	return a * b ;

}

double dev(int a, int b) {
	return a / b;
	
}

long int abs(int a, int b) {
	int powered = 1;
	for (int i = 0; i < b; ++i) {
		powered *= a;
	}
	return powered;
		
	
	

}
