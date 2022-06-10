// Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <clocale>

class Figura {
public:
    Figura() { countstor = 0, name = "Фигура"; }
    
    
    void print() {
        std::cout << get_name() << ": " << get_sides_count() << '\n';
    }

protected:
    int countstor;
    std::string name;
    Figura(int count, std::string name) { countstor = count, this->name = name; }
    int get_sides_count() {

        return  countstor;
    }

    std::string get_name() {

        return name;
    }
};

class Triple : public Figura 
{
public:
    Triple(): Figura(3,"Треугольник") { }
    
};

class Quadr : public Figura 
{
  public: 
      Quadr():Figura(4, "Четырехугольник") {  }

   
};

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Количество сторон : " << std::endl;
    
    Figura f;
    f.print();
    
    

    Triple t ;
   
    t.print();
  
   
    Quadr q ;
    q.print();
    
    
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
