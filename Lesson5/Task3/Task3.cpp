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
        if (check(number_stor) == true) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Не правильная" << std::endl;
        }
        std::cout << "Количество сторон: " << number_stor << std::endl;
    }
    virtual bool check(int number_stor) {
        if (number_stor == 0)
            return true;
        else
            return false;
    }
};



class Triple : public Figura {
public:
    Triple() : Figura(3,"Треугольник") { a = 30, b = 35, c = 50, A = 30, B = 60, C = 70; }
    
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
    bool check(int number_stor) override {
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


protected:

    bool check(int number_stor) override {

        if (Triple::check(number_stor) == true && C == 90)
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

protected:
    bool check(int number_stor) override {

        if (Triple::check(number_stor) == true && a == c && A == C)
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
protected:
    bool check(int number_stor) override {

        if (Triple::check(number_stor) == true && a == b && b == c && A == 60 && B == 60)
            return true;
        else
            return false;

    }
};

class Four : public Figura {
public:
    
    Four() : Figura(4,"Четырехугольник") { a = 30, b = 35, c = 50, d = 30, A = 30, B = 60, C = 70, D = 90; }
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
    bool check(int number_stor) override {
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
    void show_info() override
    {
        Figura::show_info();
    }
    Paralelogram() :Four(20, 25, 120, 60, "Паралелограм") { }

protected:
    Paralelogram(int a, int b, int A, int B, std::string name) : Four(a, b, A, B, name) {  }

    bool check(int number_stor) override {

        if (Four::check(number_stor) == true && A == C && B == D && a == c && b == d)
            return true;
        else
            return false;

    }
};
class Romb : public Paralelogram
{
public:

    Romb() :Paralelogram(25, 25, 130, 70, "Ромб") {

    }
    void show_info() override
    {
        Figura::show_info();
    }
protected:
    bool check(int number_stor) override {

        if (Paralelogram::check(number_stor) == true && a + c == b + d)
            return true;
        else
            return false;

    }
};
class Pramoug : public Paralelogram
{
public:
    void show_info() override
    {
        Figura::show_info();
    }

    Pramoug() :Paralelogram(20, 40,90, 90, "Прямоугольник") { }
protected:
    Pramoug(int a, std::string name) : Paralelogram(a, a, 90, 90, name) {  }

    bool check(int number_stor) override {

        if (Paralelogram::check(number_stor) == true && A == B && C == D)
            return true;
        else
            return false;

    }

};
class Quad : public Pramoug
{
public:

    Quad() : Pramoug(20, "Квадрат") {

    }
    void show_info() override
    {
        Figura::show_info();
    }
protected:
    bool check(int number_stor) override {

        if (Pramoug::check(number_stor) == true && (a == b && c == d))
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





