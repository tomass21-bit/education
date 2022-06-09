// Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <clocale>
const int ugol = 90; // Прямой угол
class Figura {
public:
    void get_name() {
        std::cout << name << ": " << std::endl;
    }
    
    Figura() {
        a = 0, b = 0, c = 0, d = 0, A = 0, B = 0, C = 0, D = 0, name = "Фигура";
    }

    


protected:
    std::string stor = "Стороны";
    std::string angle = "Углы";
    std::string name;
    int a;
    int b;
    int c;
    int d;
    int A;
    int B;
    int C;
    int D;
   
    Figura(int a, int b, int c, int d, int A, int B, int C, int D, std::string name) {
        this->a = a, this->b = b, this->c = c, this->d = d, this->A = A, this->B = B, this->C = C, this->D = D, this->name = name;
    }
     Figura(int a, int b, int c, int A, int B, int C, std::string name) {
        this->a = a, this->b = b, this->c = c, this->A = A, this->B = B, this->C = C, this->name = name;
    }
    
};



class Triple : public Figura {
public:
    void get_parametrs() {
        std::cout << stor << ":"<<" " << "a=" << a << "\t" << "b=" << b << "\t" << "c=" << c << std::endl <<
                     angle << ":"<<"\t" << "A=" << A << "\t" << "B=" << B << "\t" << "C=" << C << std::endl << std::endl;

    }
    
    Triple() : Figura (20, 30, 40, 65, 80, 45, "Треугольник") {  }
protected:
    Triple(int a, int b, int c, int A, int B, int C, std::string name) : Figura(a, b, c, A, B, C, name) {

    }

};

class Triple_pramoug : public Triple
{
public:
    
    
    Triple_pramoug() : Triple(30, 35, 50, 30, 60,ugol , "Прямоугольный треугольник") {  }
    
};

class Triple_ravnobed : public Triple
{
public:
   
    Triple_ravnobed() : Triple(20, 40, 20, 50, 70, 30, "Равнобедренный треугольник") {  }
    
};
class Triple_ravnostor : public Triple
{
public:
    
    Triple_ravnostor() : Triple(20, 20, 20, 60, 60, 60, "Равнобедренный треугольник") { }
};

class Four : public Figura {
public:
    void get_parametrs() {
        std::cout << stor << ":"<<" " << "a=" << a << "\t" << "b=" << b << "\t" << "c=" << c << "\t" << "d=" << d << std::endl <<
                    angle << ":"<<"\t" << "A=" << A << "\t" << "B=" << B << "\t" << "C=" << C << "\t" << "D=" << D << std::endl << std::endl;

    }
    
    Four(): Figura(20, 25, 40, 45, 60, 80, 90, 80, "Четырёхугольник") {  }
  protected:
      Four(int a, int b, int A, int B,  std::string name) : Figura(a, b, a, b, A, B, A, B, name) {  }
};


class Paralelogram : public Four
{
public:
   
    Paralelogram() :Four (20, 25, 120, 60, "Паралелограм") { }

protected:
    Paralelogram(int a, int b, int A, int B, std::string name) : Four(a, b,  A, B,  name) {  }
};
class Romb : public Paralelogram
{
public:
    
    Romb() :Paralelogram (25, 25, 130, 70, "Ромб") {
        
    }
};
class Pramoug : public Paralelogram
{
public:
   
    Pramoug() :Paralelogram(20, 40, ugol, ugol, "Прямоугольник") { }
protected:
    Pramoug(int a, std::string name) : Paralelogram(a, a, ugol, ugol, name) {  }
};
class Quad : public Pramoug
{
public:
   
    Quad() : Pramoug(20,  "Квадрат") {
        
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");
    
    Triple t ;
    t.get_name();
    t.get_parametrs();
    
    Triple_pramoug pr;
    pr.get_name();
    pr.get_parametrs();
   
    Triple_ravnobed rb;
    rb.get_name();
    rb.get_parametrs();
   
    Triple_ravnostor rs;
    rs.get_name();
    rs.get_parametrs();

    Four f ;
    f.get_name();
    f.get_parametrs();

    Pramoug pra ;
    pra.get_name();
    pra.get_parametrs();
    
    Quad q ;
    q.get_name();
    q.get_parametrs();
    
    Paralelogram par ;
    par.get_name();
    par.get_parametrs();

    Romb r;
    r.get_name();
    r.get_parametrs();

   


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
