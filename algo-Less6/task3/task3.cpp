// task3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <cmath>


int find_substring_light_rabin_karp(const std::string& string, const std::string& string_find) {
    int size1 = string.length();
    int size2 = string_find.length();
    for (int i = 0; i < size1; i++)
    {
        int m = 0;
        for (int j = 0; j < size2; j++)
        {
            
            if (string[i + j] != string_find[j]) {
                m = 0;
                break;
            }
            else if (string[i + j] == string_find[j]) {
                m += 1;
                if (m == size2) {
                    return i;
                }
            }
            
        }
    }
    
    return -1;

}
int main()
{
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);
    std::string string;
    std::string string_find;
    std::cout << "Введите строку, в которой будет осуществляться поиск: ";
    std::cin >> string;
    std::cout << "\n";
    do {
        std::cout << "Введите подстроку, которую нужно найти: ";
        std::cin >> string_find;
        std::cout << "\n";

        std::cout << "Подстрока " << string_find;
        int index = find_substring_light_rabin_karp(string, string_find);
        if (index == -1)
            std::cout << " не найдена \n";
        else
            std::cout << " найдена по индексу " << index << std::endl;
    } while (string_find != "exit");
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
