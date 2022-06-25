#include "Figura.h"
//#include "Four.h"
//#include "Paralelogram.h"
//#include "Pramoug.h"
//#include  "quad.h"
//#include "Romb.h"
#include "Triple.h"
#include "Triple_pramoug.h"
#include "Triple_ravnobed.h"
#include "Triple_ravnostor.h"
#include <string>

//class Figura;

    Triple:: Triple() : Figura(3, "Треугольник") { a = 30, b = 35, c = 50, A = 30, B = 60, C = 70; }
    Triple::Triple(int a, int b, int c, int A, int B, int C) : Figura(3, "Треугольник") {
        this->a = a, this->b = b, this->c = c, this->A = A, this->B = B, this->C = C;
    }
    void  Triple::show_info() {
        Figura::show_info();
    }

    Triple::Triple(int a, int b, int c, int A, int B, int C, std::string name) : Figura(3, name) {
        this->a = a, this->b = b, this->c = c, this->A = A, this->B = B, this->C = C;
    }
    void  Triple::print_sides()  {
        std::cout << stor << ":" << " " << "a=" << a << "\t" << "b=" << b << "\t" << "c=" << c << std::endl;

    }
    void  Triple::print_angles()  {
        std::cout << angle << ":" << "\t" << "A=" << A << "\t" << "B=" << B << "\t" << "C=" << C << std::endl << std::endl;
    }
    bool   Triple::check()  {
        if (number_stor == 3 && (A + B + C) == 180)
            return true;
        else
            return false;

    }

  


