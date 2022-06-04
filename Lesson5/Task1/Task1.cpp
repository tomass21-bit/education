// Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <clocale>

class figura {
public:
    void get_sides_count() {
        std::cout << countstor << std::endl;

    }
    figura() { countstor = 0, name = "Фигура"; }
    void get_name() {
        std::cout << name << ": " ;
    }


protected:
    int countstor;
    std::string name;
    

};

class triple : public figura 
{
public:
    triple() { countstor = 3, name = "Треугольник";
    }
};

class quadr : public figura 
{
  public:
    quadr() { countstor = 4, name = "Четырёхугольник"; }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Количество сторон : " << std::endl;
    
    figura f;
    f.get_name();
    f.get_sides_count();
    

    triple t;
    t.get_name();
    t.get_sides_count();
   
    quadr q;
    q.get_name();
    q.get_sides_count();
    
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
