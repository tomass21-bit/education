#include "Figura.h"
#include "Four.h"
#include "Paralelogram.h"
#include "Pramoug.h"
#include  "quad.h"
#include "Romb.h"
#include "Triple.h"
#include "Triple_pramoug.h"
#include "Triple_ravnobed.h"
#include "Triple_ravnostor.h"
#include <iostream>
#include <string>


    void show_info() override
    {
        Figura::show_info();
    }
    void get_parametrs() {
        std::cout << stor << ":" << " " << "a=" << a << "\t" << "b=" << b << "\t" << "c=" << c << std::endl <<
            angle << ":" << "\t" << "A=" << A << "\t" << "B=" << B << "\t" << "C=" << C << std::endl << std::endl;

    }

    Triple() : Figura(3, 20, 30, 40, 65, 80, 45, "Треугольник") {  }

    Triple(int a, int b, int c, int A, int B, int C, std::string name) : Figura(3, a, b, c, A, B, C, name) {

    }
    bool check(int number_stor) override {
        if (number_stor == 3 && (A + B + C) == 180)
            return true;
        else
            return false;

    }
