// Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <clocale>


enum class month
{
    Январь = 1,
    Февраль,
    Март,
    Апрель,
    Май,
    Июнь,
    Июль,
    Август,
    Сентябрь,
    Октябрь,
    Ноябрь,
    Декабрь

};

int main()
{
    setlocale(LC_ALL, "Russian");
    int number = 0;
    do {
        std::cout << "Введите номер месяца: ";
        std::cin >> number;
        
        if (number >= 0 && number < 13)
        {
            switch (number) {
            case static_cast<int>(month::Январь):
                std::cout << "Январь" << std::endl;
                break;
            case static_cast<int>(month::Февраль):
                std::cout << "Февраль" << std::endl;
                break;
            case static_cast<int>(month::Март):
                std::cout << "Март" << std::endl;
                break;
            case static_cast<int>(month::Апрель):
                std::cout << "Апрель" << std::endl;
                break;
            case static_cast<int>(month::Май):
                std::cout << "Май" << std::endl;
                break;
            case static_cast<int>(month::Июнь):
                std::cout << "Июнь" << std::endl;
                break;
            case static_cast<int>(month::Июль):
                std::cout << "Июль" << std::endl;
                break;
            case static_cast<int>(month::Август):
                std::cout << "Август" << std::endl;
                break;
            case static_cast<int>(month::Сентябрь):
                std::cout << "Сентябрь" << std::endl;
                break;
            case static_cast<int>(month::Октябрь):
                std::cout << "Октябрь" << std::endl;
                break;
            case static_cast<int>(month::Ноябрь):
                std::cout << "Ноябрь" << std::endl;
                break;
            case static_cast<int>(month::Декабрь):
                std::cout << "Декабрь" << std::endl;
                break;
            default:
                break;
            }

        }
        else
            std::cout << "Вы ввели не корректный номер месяца. Введите чило от 1 до 12!" << std::endl;

    } while (number != 0);
    std::cout << "До свидания" << std::endl;
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
