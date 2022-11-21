#define _USE_MATH_DEFINES
#include<iostream>
#include<thread>
#include <Windows.h>


using namespace std;
unsigned queue = 0;
void user(){
do{
	
	queue++;
	cout << queue << endl;
	
		this_thread::sleep_for(1000ms);
		
	
} while (queue < 10);

	cout << queue << endl;
	return;
}



void operac(){
 do {
	 queue--;
	 cout << queue << endl;
	this_thread::sleep_for(2000ms);
	
 } while (queue > 0);

	cout << queue << endl;
	return;
}




int main()
{
	cout << thread::hardware_concurrency() << endl;
	thread T1 (user);
	thread T2(operac);
	T1.join();
	T2.join();
	
	

	return 0;
}