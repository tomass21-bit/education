// my_first_cmake_project.cpp: определяет точку входа для приложения.
//

#include <iostream>
#include <clocale>
#include <string>

int main()
{
	setlocale(LC_ALL, "Russian");
	std::string name;
	std::cout << "Введите имя: " ;
	std::cin >> name;
	std::cout << std::endl;

	std::cout <<"Здравствуйте, "<< name<< "!"<< std::endl;
	system("pause");
	return 0;
}
