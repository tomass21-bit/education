// Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <clocale>

class triple {
public:
    void get_parametrs() {
        std::cout << stor << ":"<<" " << "a=" << a << "\t" << "b=" << b << "\t" << "c=" << c << std::endl <<
                     angle << ":"<<"\t" << "A=" << A << "\t" << "B=" << B << "\t" << "C=" << C << std::endl << std::endl;

    }
    
    triple() { a=10, b=20, c=15, A=60, B=50, C=70, name = "Треугольник"; }
    void get_name() {
        std::cout << name << ": "<<std::endl;
    }


protected:
    std::string stor = "Стороны";
    std::string angle = "Углы";
    std::string name;
    int a;
    int b;
    int c;
    int A;
    int B;
    int C;
    const int ugol = 90;

};

class triple_pramoug : public triple
{
public:
    triple_pramoug(int a, int b, int c, int A, int B ) {
        this->a=a, this->b=b, this->c=c, this->A=A, this->B=B, C=ugol, name = "Прямоугольный треугольник";
    }
    triple_pramoug() { a = 10, b = 20, c = 15, A = 60, B = 50, C =ugol , name = "Прямоугольный треугольник"; }
    
};

class triple_ravnobed : public triple
{
public:
    triple_ravnobed(int a, int b, int A, int B) {
        this->a = a, this->b = b , this-> c = a, this->A = A, B = 40, this-> C = A, name = "Равнобедренный треугольник";
    }
    triple_ravnobed() { a = 10, b = 20, c = 15, A = 60, B = 50, C = ugol, name = "Равнобедренный треугольник"; }
    
};
class triple_ravnostor : public triple
{
public:
    triple_ravnostor(int a,int A) {
        this-> a = a, this-> b = a, this-> c =a , this-> A = A, this->B = A, C = A, name = "Равносторонний треугольник";
    }
};

class four {
public:
    void get_parametrs() {
        std::cout << stor << ":"<<" " << "a=" << a << "\t" << "b=" << b << "\t" << "c=" << c << "\t" << "d=" << d << std::endl <<
                    angle << ":"<<"\t" << "A=" << A << "\t" << "B=" << B << "\t" << "C=" << C << "\t" << "D=" << D << std::endl << std::endl;

    }
    four() { a = 10, b = 7, c = 9, d=20, A = 75, B = 65, C = 65, D = 90, name = "Четырёхугольник"; }
    void get_name() {
        std::cout << name << ": "<<std::endl;
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
    const int dlina1 = 20;  // Значение для конструктора по умолчанию стороны а
    const int dlina2 = 30;  // Значение для конструктора по умолчанию стороны b
    const int ugol = 90;   // Значение прямого угла

};


class paralelogram : public four
{
public:
    paralelogram(int a, int b, int A, int B) {
        this->  a = a, this-> b = b, this-> c = a, this-> d = b, this-> A = A , this-> B = B, this-> C = A , this->D = B, name = "Паралелограм";
    }

    paralelogram() {
        this->a = dlina1, this->b = dlina2, this->c = dlina1, this->d = dlina2, this->A = 60, this->B = 120, this->C = 60, this->D = 120, name = "Паралелограм";
    }

};
class romb : public paralelogram
{
public:
    romb(int a,  int A, int B) {
        this->a = a, this->b = a, this->c = a, this->d = a, this->A = A, this->B = B, this->C = A, this->D = B, name = "Ромб";
    }
};
class pramoug : public paralelogram
{
public:
    pramoug(int a, int b) {
        this->a = a, this->b = b, this->c = a, this->b, A = ugol, B = ugol, C = ugol, D = ugol, name = "Прямоугольник";
    }
    pramoug() {
        this->a = dlina1, this->b = dlina2, this->c = dlina1, this->d = dlina2, this->A = ugol, this->B = ugol, this->C = ugol, this->D = ugol, name = "Паралелограм";
    }
};
class quad : public pramoug
{
public:
    quad(int a) {
        this->a = a , this-> b = a, this-> c = a, this-> d = a, A = ugol, B = ugol, C = ugol, D = ugol, name = "Квадрат";
    }
    quad() {
        this->a = dlina2, this->b = dlina2, this->c = dlina2, this->d = dlina2, A = ugol, B = ugol, C = ugol, D = ugol, name = "Квадрат";
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");
    

    


    triple t;
    t.get_name();
    t.get_parametrs();
    
    triple_pramoug pr(20,20,40,60,80);
    pr.get_name();
    pr.get_parametrs();

    triple_ravnobed rb(20,30,90,70);
    rb.get_name();
    rb.get_parametrs();
   
    triple_ravnostor rs(20,60);
    rs.get_name();
    rs.get_parametrs();

    four f;
    f.get_name();
    f.get_parametrs();

    pramoug pra (30,40);
    pra.get_name();
    pra.get_parametrs();
    
    quad q (35);
    q.get_name();
    q.get_parametrs();
    
    paralelogram par (20,25,120,60);
    par.get_name();
    par.get_parametrs();

    romb r(40,50,80);
    par.get_name();
    par.get_parametrs();

   


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
