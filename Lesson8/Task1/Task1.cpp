// Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <windows.h>

class bad_length : public std::exception
{
public:
    bad_length(std::string error): exception(" ") {
        std::cout << error ;
    }
   
};

int function(std::string str, int forbidden_length) {
    
        int size = str.length();

    
        if (size == forbidden_length) throw bad_length( "Вы ввели слово запретной длины! До свидания. Слово повлекшее завершение програмы "+ str + " запрещенный размер " + std::to_string(forbidden_length) );
        
        return size;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string str;
    int count=0;
   
    
    std::cout << "Введите запретную длину: ";
    std::cin >> count;
    std::cout << "\n";
    try {
        do {
            std::cout << "Введите слово: ";
            std::cin >> str;
            std::cout << "\n";
            std::cout << "Длина слова " << str << " равна " << function(str, count)<<std::endl;
        } while (function(str, count) != 0);
        return 0;

    }
    catch (const bad_length& e) {
        std::cout << e.what() << std::endl;

    }
   
    catch (...) {
        std::cout << "Неизвестная ошибка!" << std::endl;
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
