// task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>
#include <windows.h>

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
using namespace std::chrono_literals;

std::mutex m;



void imit_calculation(const int leng, const int thread) {
	auto start = std::chrono::high_resolution_clock::now();
	
		
		double temp = 100.0 / leng;
		double progress = 0.0;
		while (progress < 1.0) {
			
			std::cout << " \r";
			int barWidth = 100;
			std::string bar = "";

			int pos = barWidth * progress;
			
			for (int i = 0; i < barWidth; ++i) {
				if (i < pos)  bar.push_back( '|' );
				else bar.push_back('.');
			}
			m.lock();
			gotoxy(0, thread*2);
			std::cout << "Поток " << thread + 1 <<"  ";
			
			std::cout << bar;
			std::cout << int(progress * 100.0)<<"%";
			
			std::this_thread::sleep_for(2ms);
			m.unlock();
			
			progress += temp;
			
			
		}
		auto end = std::chrono::high_resolution_clock::now();

		std::chrono::duration<double, std::milli> time = end - start;
		m.lock();
		gotoxy(115, thread*2);
		std::cout << " Затрачено времени  " << time.count();
		std::this_thread::sleep_for(2ms);
		m.unlock();
	
}
int main()
{
	setlocale(LC_ALL, "Rus");

	int thread = 16;
	int lengh_all = 200000;
	std::vector <std::thread> thr;
	int lengh = lengh_all / thread;
	
	for (int i = 0; i < thread; ++i) {
		
		
		thr.push_back(std::thread( imit_calculation, lengh, i));
		
		
	}

		for (int th = 0; th < thread; th++) {
			
			thr[th].join();
		}
		
		
	
	
	gotoxy(0, thread * 2);
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
