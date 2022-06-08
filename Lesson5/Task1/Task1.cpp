// Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <clocale>

class Figura {
public:
    void get_sides_count() {
        std::cout << countstor << std::endl;

    }
    Figura(int count, std::string name ) { countstor = count, this->name = name; }
    Figura() { countstor = 0, name= "Фигура"; }
    void get_name() {
        std::cout << name << ": " ;
    }


protected:
    int countstor;
    std::string name;
    

};

class Triple : public Figura 
{
public:
    Triple() { 
        countstor = 0, name = "Фигура";
    }
    Triple(int count, std::string name) : Figura ( count, name) {
        /*if (count==3)
        countstor = count , name = "Треугольник";
        else 
        std::cout << "У треугольника 3 стороны!" << std::endl;*/
    }
};

class Quadr : public Figura 
{
  public:
    Quadr() { countstor = 0, name = "Фигура"; }

    Quadr(int count, std::string name) : Figura(count, name) {
        /* if (count == 4)
             countstor = 3, name = "Четырёхугольник";
         else
             std::cout << "У треугольника 3 стороны!" << std::endl;*/
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Количество сторон : " << std::endl;
    
    Figura f;
    f.get_name();
    f.get_sides_count();
    

    Triple t (3, "Треугольник");
    t.get_name();
    t.get_sides_count();
   
    Quadr q (4, "Четырёхугольник");
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
