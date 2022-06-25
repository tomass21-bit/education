#pragma once
#include "Figura.h"
#include <iostream>
#include <string>
class Four : public Figura {
public:

    Four() : Figura(4, "Четырехугольник") { a = 30, b = 35, c = 50, d = 30, A = 30, B = 60, C = 70, D = 90; }
    Four(int a, int b, int c, int d, int A, int B, int C, int D);
    void show_info() override;
    void print_sides() override;


    void print_angles() override;
    bool check() override;

protected:

    Four(int a, int b, int A, int B, std::string name);

    int a=0;
    int b=0;
    int c=0;
    int d=0;
    int A=0;
    int B=0;
    int C=0;
    int D=0;


};