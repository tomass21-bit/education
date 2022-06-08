﻿// Task3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <clocale>
const int ugol = 90; // Прямой угол
class Figura {
public:
    
    
    
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
   
    Figura( int number_stor, int a, int b, int c, int d, int A, int B, int C, int D, std::string name) {
        this->number_stor= number_stor, this->a = a, this->b = b, this->c = c, this->d = d, this->A = A, this->B = B, this->C = C, this->D = D, this->name = name;
    }
    Figura(int number_stor, int a, int b, int c, int A, int B, int C, std::string name) {
       this-> number_stor = number_stor, this->a = a, this->b = b, this->c = c, this->A = A, this->B = B, this->C = C, this->name = name;
    }
    Figura() {
        a = 0, b = 0, c = 0, d = 0, A = 0, B = 0, C = 0, D = 0, name = "Фигура";
    }
    virtual bool check(int number_stor) {
        if (number_stor == 0)
            return true;
        else
            return false;
    }
    


protected:
    std::string stor = "Стороны";
    std::string angle = "Углы";
    std::string name;
    int number_stor;
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
    std::string states;
    
   

    

};



class Triple : public Figura {
public:
    void show_info() override
    {
        Figura::show_info();
    }
    
    void get_parametrs() {
        std::cout << stor << ":" << " " << "a=" << a << "\t" << "b=" << b << "\t" << "c=" << c << std::endl <<
            angle << ":" << "\t" << "A=" << A << "\t" << "B=" << B << "\t" << "C=" << C << std::endl << std::endl;

    }
    Triple(int a, int b, int c, int A, int B, int C, std::string name) : Figura(3,a, b, c, A, B, C, name) {
        
    }
    Triple() { a = 0, b = 0, c = 0, A = 0, B = 0, C = 0, name = "Треугольник"; }
protected:
    
    bool check(int number_stor) override {
    if (number_stor == 3 && (A + B + C) == 180)
        return true;
    else
        return false;

     }


};

class Triple_pramoug : public Triple
{
public:

    void show_info() override
    {
        Figura::show_info();
    }

    Triple_pramoug(int a, int b, int c, int A, int B, std::string name) : Triple(a, b, c, A, B, ugol, name) {
        
    }
    Triple_pramoug() { a = 0, b = 0, c = 0, A = 0, B = 0, C = 90, name = "Прямоугольный треугольник"; }

protected:

    bool check(int number_stor) override {
        
        if (Triple::check(number_stor)==true && C == 90)
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
    Triple_ravnobed(int a, int b, int A, int B, std::string name) : Triple(a, b, a, A, B, A, name) {

    }
    Triple_ravnobed() { a = 0, b = 0, c = 0, A = 0, B = 0, C = 0, name = "Равнобедренный треугольник"; }
    bool check(int number_stor) override {
        
        if (Triple::check(number_stor)==true && a==c && A==C)
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
    Triple_ravnostor(int a, int A, std::string name) : Triple(a, a, a, A, A, A, name) {

    }
    Triple_ravnostor() {
        a = 0, b = 0, c = 0, A = 0, B = 0, C = 0, name = "Равносторонний треугольник";
    }
    bool check(int number_stor) override {

        if (Triple::check(number_stor) == true && a==b&& b==c && A == 60 && B==60)
            return true;
        else
            return false;

    }
};

class Four : public Figura {
public:
     void show_info() override
    {
        Figura::show_info();
    }
    void get_parametrs() {
        std::cout << stor << ":" << " " << "a=" << a << "\t" << "b=" << b << "\t" << "c=" << c << "\t" << "d=" << d << std::endl <<
            angle << ":" << "\t" << "A=" << A << "\t" << "B=" << B << "\t" << "C=" << C << "\t" << "D=" << D << std::endl << std::endl;

    }
    Four(int a, int b, int c, int d, int A, int B, int C, int D, std::string name) : Figura(4, a, b, c, d, A, B, C, D, name) {

    }
    Four() { a = 10, b = 7, c = 9, d = 20, A = 75, B = 65, C = 65, D = 90, name = "Четырёхугольник"; }
    bool check(int number_stor) override {
        if (number_stor == 4 && (A + B + C+ D) == 360)
            return true;
        else
            return false;

    }
};


class Paralelogram : public Four
{

public:
    void show_info() override
    {
        Figura::show_info();
    }
    Paralelogram(int a, int b, int A, int B, std::string name) : Four(a, b, a, b, A, B, A, B, name) {
        this->a = a, this->b = b, this->c = a, this->d = b, this->A = A, this->B = B, this->C = A, this->D = B, this->name = name;
    }

    Paralelogram() {
        this->a = dlina1, this->b = dlina2, this->c = dlina1, this->d = dlina2, this->A = 60, this->B = 120, this->C = 60, this->D = 120, name = "Паралелограм";
    }
    bool check(int number_stor) override {

        if (Four::check(number_stor) == true && A==C && B==D&& a==c && b==d)
            return true;
        else
            return false;

    }
};


class Romb : public Paralelogram
{
public:
    void show_info() override
    {
        Figura::show_info();
    }
    Romb(int a, int A, int B, std::string name) : Paralelogram(a, a, A, B, name) {

    }
    Romb() {
        this->a = dlina1, this->b = dlina1, this->c = dlina1, this->d = dlina1, this->A = 60, this->B = 120, this->C = 60, this->D = 120, name = "Ромб";
    }
    bool check(int number_stor) override {

        if (Paralelogram::check(number_stor) == true && a+c==b+d)
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
    Pramoug(int a, int b, std::string name) : Paralelogram(a, b, ugol, ugol, name) {

    }
    Pramoug() {
        this->a = dlina1, this->b = dlina2, this->c = dlina1, this->d = dlina2, this->A = ugol, this->B = ugol, this->C = ugol, this->D = ugol, name = "Прямоугольник";
    }
    bool check(int number_stor) override {

        if (Paralelogram::check(number_stor) == true && A==B && C==D)
            return true;
        else
            return false;

    }
};
class Quad : public Pramoug
{
public:
    void show_info() override
    {
        Figura::show_info();
    }
    Quad(int a, std::string name) : Pramoug(a, a, name) {

    }
    Quad() {
        this->a = dlina2, this->b = dlina2, this->c = dlina2, this->d = dlina2, A = ugol, B = ugol, C = ugol, D = ugol, name = "Квадрат";
    }
    bool check(int number_stor) override {

        if (Pramoug::check(number_stor) == true && (a==b && c==d) )
            return true;
        else
            return false;

    }
};


int main()
{
    setlocale(LC_ALL, "Russian");

    Triple t(20, 30, 40, 60, 80, 40, "Треугольник");
    t.show_info();
    t.get_parametrs();

    Triple_pramoug pr(30, 35, 50, 60, 30, "Прямоугольный треугольник");
    pr.show_info();
    pr.get_parametrs();

    Triple_ravnobed rb(20, 50, 70, 30, "Равнобедренный треугольник");
    rb.show_info();
    rb.get_parametrs();

    Triple_ravnostor rs(20, 60, "Равносторонний треугольник");
    rs.show_info();
    rs.get_parametrs();

    Four f(20, 25, 40, 45, 60, 80, 90, 80, "Четырёхугольник");
    f.show_info();
    f.get_parametrs();

    Pramoug pra(30, 40, "Прямоугольник");
    pra.show_info();
    pra.get_parametrs();

    Quad q(35, "Квадрат");
    q.show_info();
    q.get_parametrs();

    Paralelogram par(20, 25, 120, 60, "Паралелограм");
    par.show_info();
    par.get_parametrs();

    Romb r(40, 100, 80, "Ромб");
    r.show_info();
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
