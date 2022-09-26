// task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <windows.h>



void dsf(int** arr, const int size, int vertex) {
	std::string* arr_visit = new std::string[size];
	std::queue <int> verh;
	verh.push(vertex);



	while (verh.empty() != true) {
		vertex = verh.front();
		verh.pop();
		arr_visit[vertex] = "да";
		std::cout << vertex + 1 << " ";
		
		
		if (verh.size() == 0) {
			for (int i = 0; i < size; i++) {

				if (arr[vertex][i] == 1) {
					if (arr_visit[i] != "да") {
						verh.push(i);
					}
				}
			}
		}
	}
	
	


	delete[] arr_visit;
}





int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size = 0;
	int num = 0;
	int versh = 0;

	std::ifstream fin("graf.txt"); // пытаемся открыть файл
	if (fin.is_open()) {
		std::string s;
		fin >> s;
		size = stoi(s);
		int** arr = new int* [size];
		for (int i = 0; i < size; i++) {
			arr[i] = new int[size];
		}

		while (!fin.eof()) {

			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					fin >> s;
					num = stoi(s);
					arr[i][j] = num;
				}
			}

		}
		std::cout << "В графе " << size << " вершин. Введите номер вершины, с которой начнётся обход: ";
		std::cin >> versh;
		dsf(arr, size, versh - 1);


		for (int i = 0; i < size; i++) {
			delete[] arr[i];
		}
		delete[] arr;

	}



	else {
		std::cout << "Не получилось открыть файл!" << std::endl;

	}


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
