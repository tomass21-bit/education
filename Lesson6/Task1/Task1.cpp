﻿// Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <clocale>
#include "Calculator.h"

int main()
{
    int a;
    int b;
    int c;
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите первое число: ";
    std::cin >> a;
    std::cout <<std::endl<< "Введите второе число: ";
    std::cin >> b;
    do {
        std::cout << std::endl << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
        std::cin >> c;
        std::cout << std::endl;
        if (c < 0 || c>5) {
            std::cout <<  "Вы ввели неверное значение попробуйте еще раз! \n";
        }
                } while (!(c > 0 && c < 6));

    switch (c) {
    case 1: std::cout << a << " плюс " << b << " = " << summ(a, b) << std::endl;
        break;
    case 2: std::cout << a << " минус " << b << " = " << minus(a, b) << std::endl; 
        break;
    case 3: std::cout << a << " умножить " << b << " = " << times(a, b) << std::endl; 
        break;
    case 4:
        if (b == 0) {
            std::cout << " Делить на ноль нельзя! " << std::endl;
        }
        else
            std::cout << a << " делить " << b << " = " << dev(a, b) << std::endl; 
        break;
    case 5: std::cout << a << " в степени  " << b << " = " << abs(a, b) << std::endl;
        break;
    
    }
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
