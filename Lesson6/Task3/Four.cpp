#include "Figura.h"
#include "Four.h"
#include "Paralelogram.h"
#include "Pramoug.h"
#include  "quad.h"
#include "Romb.h"





  
   Four::Four(int a, int b, int c, int d, int A, int B, int C, int D) : Figura(4, "Четырехугольник") {
        this->a = a, this->b = b, this->c = c, this->d = d, this->A = A, this->B = B, this->C = C, this->D = D;
    }
   void Four::show_info()   {
        Figura::show_info();
    }

    void Four::print_sides()  {

        std::cout << stor << ":" << " " << "a=" << a << "\t" << "b=" << b << "\t" << "c=" << c << "\t" << "d=" << d << std::endl;
    }


    void Four::print_angles()  {
        std::cout << angle << ":" << "\t" << "A=" << A << "\t" << "B=" << B << "\t" << "C=" << C << "\t" << "D=" << D << std::endl << std::endl;

    }
    bool Four::check()  {
        if (number_stor == 4 && (A + B + C + D) == 360)
            return true;
        else
            return false;

    }


    Four::Four(int a, int b, int A, int B, std::string name) : Figura(4, name) {
        this->a = a, this->b = b, this->c = a, this->d = b, this->A = A, this->B = B, this->C = A, this->D = B;
    }

   