// Task3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <windows.h> 
struct adress {
    std::string  country = "empty";
    std::string  city = "empty";
    std::string  street = "empty";
    std::string NumderHouse = "empty";
    unsigned short NumberFlat = 0;
    unsigned index =0;
};
void printStruct(const adress& a) {
    std::cout << "Страна : " << a.country<<std::endl<< "Город : " << a.city << std::endl
        << "Улица : " << a.street << std::endl<< "Номер дома : " << a.NumderHouse << std::endl
        << "Страна : " << a.country << std::endl<< "Номер квартиры : " << a.NumberFlat << std::endl<< "Индекс : " << a.index << std::endl<< std::endl;
}
int main()

{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    adress ros;
    adress mos;
    adress kra;

    ros.country = "Россия";
    ros.city = "Ростов-на-дону";
    ros.street = "Ленина";
    ros.NumderHouse = "171А";
    ros.NumberFlat = 51;
    ros.index = 8412000;

    mos.country = "Россия";
    mos.city = "Москва";
    mos.street = "Мичурина";
    mos.NumderHouse = "20";
    mos.NumberFlat = 9;
    mos.index = 8917010;

    kra.country = "Россия";
    kra.city = "Краснодар";
    kra.street = "Весенняя";
    kra.NumderHouse = "33";
    kra.NumberFlat = 10;
    kra.index = 51452010;

    printStruct(ros);
    printStruct(mos);
    printStruct(kra);
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
