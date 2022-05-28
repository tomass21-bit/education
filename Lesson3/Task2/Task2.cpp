// Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <string>


class Counter {
public:
    int count ;
    void  plus() {
        count++;   
    }
    void minus() {
        count--;
    }
    void ravno() {
        std::cout<<count<<std::endl;
    }
    void stop() {
        std::cout << "До свидания!" << std::endl;
        
    }
    void set (int count) {
        this->count = count;

    }
    Counter() {
        count = 0;

    }
};

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    std::string vopros;
    int count;
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: " ;
    std::cin >> vopros;
    std::cout << std::endl;
    Counter schet;
    if (vopros == "Да" || vopros == "да") {
        std::cout << "Введите начальное значение счётчика: " ;
        std::cin >> count;
        std::cout << std::endl;
        schet.set (count);
    }
    else if (vopros == "Нет" || vopros == "нет") {
        schet.set(1);
    }
    else
    {
        std::cout << "Вы ввели неправильный ответ, досвидания! " << std::endl;
        return 0;
    }
    

    do {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): " ;
        std::cin >> vopros;
        std::cout << std::endl;
        if (vopros == "+") {
            schet.plus();
        }
        else if (vopros == "-") {
            schet.minus();
        }
        else if (vopros == "=") {
            schet.ravno();
        }
        else if (vopros == "-") {
            schet.minus();
        }
        else if (vopros == "x"|| vopros == "х") {
            schet.stop();
        }
        else
            std::cout << "Введена неизвестная команда! \n";
    } while (vopros != "x");



    
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
