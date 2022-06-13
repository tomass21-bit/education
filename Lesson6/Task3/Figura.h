#pragma once
#include <string>
class Figura {
public:

    virtual void show_info();

    virtual bool check(int number_stor);

    Figura();


protected:
    std::string stor = "Стороны";
    std::string angle = "Углы";
    std::string name;
    int number_stor;
    std::string states;
    int a;
    int b;
    int c;
    int d;
    int A;
    int B;
    int C;
    int D;

    Figura(int number_stor, int a, int b, int c, int d, int A, int B, int C, int D, std::string name);
    Figura(int number_stor, int a, int b, int c, int A, int B, int C, std::string name);

};