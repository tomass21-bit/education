﻿// task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <variant>
#include <iostream>
#include <vector>
#include <string>
std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}
void print_vector(std::vector <int> vect) {
	for (int i = 0; i < vect.size(); i++) {
		std::cout << vect[i] << " ";
	}
}
int main()
{
	
	
	if (std::holds_alternative<int>(get_variant()) == true) {
		std::cout << std::get<int>(get_variant()) * 2;
		
	}
	else if (std::holds_alternative<std::string>(get_variant())==true) {
		std::cout << std::get<std::string>(get_variant());

	}
	else if (std::holds_alternative<std::vector<int>>(get_variant()) == true) {
		print_vector(std::get<std::vector<int>>(get_variant()));
	}
	return 0;
	/*std::holds_alternative<int>(get_variant()) ? w = std::get<int>(get_variant()) * 2 : std::holds_alternative<std::string>(get_variant()) ?
		w = std::get<std::string>(get_variant()) : std::holds_alternative<std::vector<int>>(get_variant()) ? w = std::get<std::vector<int>>(get_variant()) : w = std::get<int>(get_variant()) * 2;*/
	
		 

	
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
