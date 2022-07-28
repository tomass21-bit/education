// task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <windows.h>

int level(const int& i) {
    if (i == 0)
        return 0;
    else if (i == 1 || i == 2)
        return 1;
    else if (i > 2 && i < 7)
        return 2;
    else
        return 3;
}
std::string position(const int& i) {
    if (i == 0)
        return "root ";
    else if (i % 2 != 0)
        return "left"; //Если после деления на 2 остается остаток Это левый элемент
    else
        return "right"; //Если после деления на 2 нет остатка Это правый элемент
}
int parent(const int& i) {    //вывод индекса родительского элемента
    if (i % 2 != 0)
        return  (i - 1) / 2;
    else
        return (i - 2) / 2;
}
void print_element(const int* arr,const int& i) {
    i == 0 ? std::cout << level(i) << " " << position(i) << arr[i] << std::endl : std::cout << level(i) << " " << position(i) << "(" << arr[parent(i)] << ") " << arr[i] << std::endl;
}
void print_pyramid(const int* arr, const unsigned short& size) {
    for (int i = 0; i < size; ++i) {
        print_element(arr,i);
           
    }

}
void moved ( int& i, unsigned short size, std::string enter) {
    if (enter == "up") {
        int i2 = parent(i);
        if (i2 < 0) {
        std::cout << "Ошибка! Отсутствует родитель! \n";
        }
        else {
            i = i2;
            std::cout << "ОК \n";
        }
    }
    else if (enter == "left") {
       int i2 = 2 * i + 1;
       if (i2 > size - 1)
           std::cout << "Ошибка! Отсутствует левый потомок! \n";
       else {
           i = i2;
           std::cout << "ОК \n";
       }
    }
    else if (enter == "right") {
        int i2 = 2 * i + 2;
        if (i2 > size - 1)
            std::cout << "Ошибка! Отсутствует правый потомок! \n";
        else {
            i = i2;
            std::cout << "ОК \n";
        }
    }
    else if (enter == "exit") {
        return;
    }
    else

        std::cout << "Ошибка, такая команда не определена! \n";
}

int main()
{
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);
    int arr[]{ 16, 11, 9, 10, 5, 6, 8, 1, 2, 4, 9, 67, 1 };
    int j = 0;
    unsigned short  size = sizeof(arr) / sizeof(arr[0]);
    std::string enter;
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i)
    {
     std::cout << arr[i] << " ";
    }
    std::cout << " \n";
    std::cout << "Пирамида: \n";
    print_pyramid(arr, size);
    do {
       std::cout << "Вы находитесь здесь: ";
       print_element(arr, j);
       std::cout << "Введите команду: ";
       std::cin >> enter;
       moved (j,size,enter);
       
    } while (enter != "exit");
    



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
