﻿// Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>

class calculator
{
public:
    double num1 = 0;
    double num2 = 0;

    double add() {
        return num1 + num2;
     }
     double multiply() {
         return num1 * num2;
}
     double subtract_1_2() {
         return num1 - num2;
     }
     double subtract_2_1() {
         return num2 - num1;
     }
     double divide_1_2() {
         return num1 / num2;
     }
     double divide_2_1() {
         return num2 / num1;
     }
    /* calculator(double num1, double num2) {
         this->num1 = num1;
         this->num2 = num2;
     };*/

     bool set_num1(double num1) {
         
         if (num1 != 0) {
             this->num1 = num1;
             return 1;
         }
         else
             return 0;
         
     }
    
     bool set_num2(double num2) {
         if (num2 != 0) {
             this->num2 = num2;
             return 1;
         }
         else
             return 0;
     }
     
};


int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    double num1 = 0;
    double num2 = 0;
    calculator set1;
    
    
    
    do {
        std::cout << "Введите num1: ";
        std::cin >> num1;
        std::cout << "\n ";
        num1=set1.set_num1(num1);
        if (num1 == 0) {
            std::cout << "Неверный ввод!\n";
        }
    } while (num1 == 0);
       
    do{
        std::cout << "Введите num2: ";
        std::cin >> num2;
        std::cout << "\n ";
        num2=set1.set_num2(num2);
        if (num2 == 0){
            std::cout << "Неверный ввод!\n";
        }
    } while (num2 == 0);
   
    
    
    

    
        std::cout << "num1 + num2 = " << set1.add() << std::endl;
   
        std::cout << "num1 * num2 = " << set1.multiply() << std::endl;
    
        std::cout << "num1 - num2 = " << set1.subtract_1_2() << std::endl;
    
        std::cout << "num2 - num1 = " << set1.subtract_2_1() << std::endl;
   
        std::cout << "num1 / num2 = " << set1.divide_1_2() << std::endl;
  
        std::cout << "num2 / num1 = " << set1.divide_2_1() << std::endl;
   
       
   
    
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
