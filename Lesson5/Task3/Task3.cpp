// Task3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <clocale>

class Figura {
public:

    void print() {
        show_info();
        print_sides();
        print_angles();
    }

    

    


protected:
    std::string stor = "Стороны";
    std::string angle = "Углы";
    std::string name;
    int number_stor;
    std::string states;
   
    Figura(int number_stor, std::string name) {this->number_stor = number_stor, this->name = name;
    }

    virtual void print_sides() {}
    virtual void print_angles() {}
    virtual void show_info() {
        std::cout << name << ": " << std::endl;
        if (check() == true) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Не правильная" << std::endl;
        }
        std::cout << "Количество сторон: " << number_stor << std::endl;
    }
    virtual bool check() {
        if (number_stor == 0)
            return true;
        else
            return false;
    }
};



class Triple : public Figura {
public:
    Triple() : Figura(3,"Треугольник") { a = 30, b = 35, c = 50, A = 30, B = 60, C = 70; }
    Triple(int a, int b, int c, int A, int B, int C) : Figura(3,"Треугольник") {
        this->a = a, this->b = b, this->c = c, this->A = A, this->B = B, this->C = C;
    }
    void show_info() override
    {
        Figura::show_info();
    }
protected:
    Triple(int a, int b, int c, int A, int B, int C, std::string name) : Figura(3,name) {
        this->a = a, this->b = b, this->c = c, this->A = A, this->B = B, this->C = C;
    }
    void print_sides() override {
        std::cout << stor << ":" << " " << "a=" << a << "\t" << "b=" << b << "\t" << "c=" << c << std::endl;

    }
    void print_angles() override {
        std::cout << angle << ":" << "\t" << "A=" << A << "\t" << "B=" << B << "\t" << "C=" << C << std::endl << std::endl;
    }
    bool check( ) override {
        if (number_stor == 3 && (A + B + C) == 180)
            return true;
        else
            return false;

    }

    int a;
    int b;
    int c;
    int A;
    int B;
    int C;
   
};

class Triple_pramoug : public Triple
{
public:
    void show_info() override
    {
        Figura::show_info();
    }

    Triple_pramoug() : Triple(30, 35, 50, 30, 60, 90, "Прямоугольный треугольник") {  }
    Triple_pramoug(int a, int b, int c, int A, int B) : Triple(a, b, c, A, B, 90, "Прямоугольный треугольник") {  }

protected:

    bool check( ) override {

        if (Triple::check( ) == true && C == 90)
            return true;
        else
            return false;

    }
};

class Triple_ravnobed : public Triple
{
public:
    void show_info() override
    {
        Figura::show_info();
    }

    Triple_ravnobed() : Triple(20, 40, 20, 50, 70, 30, "Равнобедренный треугольник") {  }
    Triple_ravnobed(int a, int b, int A, int B) : Triple(a, b, a, A, B, A, "Равнобедренный треугольник") {  }
protected:
    bool check() override {

        if (Triple::check() == true && a == c && A == C)
            return true;
        else
            return false;

    }

};
class Triple_ravnostor : public Triple
{
public:
    void show_info() override
    {
        Figura::show_info();
    }


    Triple_ravnostor() : Triple(20, 20, 20, 60, 60, 60, "Равнобедренный треугольник") { }
    Triple_ravnostor(int a) : Triple(a, a, a, 60, 60, 60, "Равноcторонний треугольник") {  }
protected:
    bool check() override {

        if (Triple::check() == true && a == b && b == c && A == 60 && B == 60)
            return true;
        else
            return false;

    }
};

class Four : public Figura {
public:
    
    Four() : Figura(4,"Четырехугольник") { a = 30, b = 35, c = 50, d = 30, A = 30, B = 60, C = 70, D = 90; }
    Four(int a, int b, int с, int в, int A, int B, int C, int D, std::string name) : Figura(4,"Четырехугольник") {
        this->a = a, this->b = b, this->c = c, this->d = d, this->A = A, this->B = B, this->C = C, this->D = D;
    }
    void show_info() override

    {
        Figura::show_info();
    }

    void print_sides() override {

        std::cout << stor << ":" << " " << "a=" << a << "\t" << "b=" << b << "\t" << "c=" << c << "\t" << "d=" << d << std::endl;
    }


    void print_angles() override {
        std::cout << angle << ":" << "\t" << "A=" << A << "\t" << "B=" << B << "\t" << "C=" << C << "\t" << "D=" << D << std::endl << std::endl;

    }
    bool check() override {
        if (number_stor == 4 && (A + B + C + D) == 360)
            return true;
        else
            return false;

    }

protected:

    Four(int a, int b, int A, int B, std::string name) : Figura(4,name) {
        this->a = a, this->b = b, this->c = a, this->d = b, this->A = A, this->B = B, this->C = A, this->D = B;
    }

    int a;
    int b;
    int c;
    int d;
    int A;
    int B;
    int C;
    int D;

    
};


class Paralelogram : public Four
{
public:
    
    Paralelogram() :Four(20, 25, 120, 60, "Паралелограм") { }
    Paralelogram(int a, int b, int A, int B) : Four(a, b, a, b, A, B, A, B, "Паралелограм") {  }
    void show_info() override
    {
        Figura::show_info();
    }
protected:
    Paralelogram(int a, int b, int A, int B, std::string name) : Four(a, b, A, B, name) {  }

    bool check() override {

        if (Four::check() == true && A == C && B == D && a == c && b == d)
            return true;
        else
            return false;

    }
};
class Romb : public Paralelogram
{
public:

    Romb() :Paralelogram(25, 25, 130, 70, "Ромб") { }
    Romb(int a, int A, int B) : Paralelogram(a, a, A, B, "Ромб") {  }
    void show_info() override
    {
        Figura::show_info();
    }
protected:
    bool check() override {

        if (Paralelogram::check() == true && a + c == b + d)
            return true;
        else
            return false;

    }
};
class Pramoug : public Paralelogram
{
public:
    
    Pramoug() :Paralelogram(20, 40,90, 90, "Прямоугольник") { }
    Pramoug(int a, int b) : Paralelogram(a, b, 90, 90, "Прямоугольник") {  }
    void show_info() override
    {
        Figura::show_info();
    }

protected:
    Pramoug(int a, std::string name) : Paralelogram(a, a, 90, 90, name) {  }

    bool check() override {

        if (Paralelogram::check() == true && A == B && C == D)
            return true;
        else
            return false;

    }

};
class Quad : public Pramoug
{
public:

    Quad() : Pramoug(20, "Квадрат") { }
    Quad(int a) : Pramoug(a, "Квадрат") { }
    void show_info() override
    {
        Figura::show_info();
    }
protected:
    bool check() override {

        if (Pramoug::check() == true && (a == b && c == d))
            return true;
        else
            return false;

    }
};









int main()
{
    setlocale(LC_ALL, "Russian");

    Triple t;
    t.print();
    

    Triple_pramoug pr;
    pr.print();

    Triple_ravnobed rb;
    rb.print();

    Triple_ravnostor rs;
    rs.print();

    Four f;
    f.print();

    Pramoug pra;
    pra.print();
    Quad q;
    q.print();
    Paralelogram par;
    par.print();

    Romb r;
    r.print();




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





