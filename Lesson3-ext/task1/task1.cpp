// task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>


class Smart_array {
public:
	Smart_array( int size1) {
		size = size1;
		arr = new int[size];

	}
	~Smart_array() {
		delete[] arr;
	}

	void add_element( int element) {
		if (i < size) {
			arr[i] = element;
			i++;
		}
		else {
			int* arr1 = new int[size * 2];
			for (int j = 0; j < size; j++) {
				arr1[j] = arr[j];
			}
			size = size * 2;
			delete[] arr;
			arr =  arr1;
			arr[i] = element;
			i++;
		}
	}
	int get_element(const int& index) {
		if (index >= i) {
			throw std::exception("Элемент по указанному индексу отсутствует");
		}
		else
		return arr[index];
		}
protected:
	int* arr;
	int i = 0;
	int size = 0;
};
int main()
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);
	try {
		Smart_array arrt(5);
		arrt.add_element(1);
		arrt.add_element(4);
		arrt.add_element(155);
		arrt.add_element(14);
		arrt.add_element(15);
		arrt.add_element(10);
		std::cout << arrt.get_element(6) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
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
