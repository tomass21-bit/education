// перегрузки.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
class MyString
{
	char* ptr = nullptr;
public:
	MyString(const char* new_ptr)
	{
		int len = strlen(new_ptr);
		ptr = new char[len + 1];
		strcpy(ptr, new_ptr);
		ptr[len] = 0;
	}
	MyString(const MyString& a)
	{
		int len = strlen(a.ptr);
		ptr = new char[len + 1];
		strcpy(ptr, a.ptr);
		ptr[len] = 0;
	}
	~MyString()
	{
		delete[] ptr;
	}
	MyString& operator=(const MyString& a)
	{
		if (a != *this)
		{
			delete[] ptr;
			int len = strlen(a.ptr);
			ptr = new char[len + 1];
			strcpy(ptr, a.ptr);
			ptr[len] = 0;
		}
		return *this;
	}
	bool operator!=(const MyString& a) const
	{
		return (ptr != a.ptr);
	}

	void print() const
	{
		std::cout << ptr;
	}
};
int main()
{
	MyString a("Hello world");
	MyString b = a;
	a = a;
	a.print();
	b.print();
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
