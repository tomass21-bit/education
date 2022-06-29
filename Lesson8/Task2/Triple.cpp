#include "Figura.h"
#include "Exception.h"
#include "Triple.h"
#include "Triple_pramoug.h"
#include "Triple_ravnobed.h"
#include "Triple_ravnostor.h"




    Triple:: Triple() : Figura(3, "Треугольник") { a = 30, b = 35, c = 50, A = 30, B = 60, C = 70; }
    Triple::Triple(int a, int b, int c, int A, int B, int C) : Figura(3, "Треугольник") {
        if ((A + B + C) != 180) {
         throw Bad_figure(Figura::name + " ( стороны " + std::to_string(a) + ", " + std::to_string(b) + ", " + std::to_string(c) +  "; углы " + std::to_string(A) +
             ", " + std::to_string(B) + ", " + std::to_string(C)  + ")" + Triple::check() );
        }
        this->a = a, this->b = b, this->c = c, this->A = A, this->B = B, this->C = C;
    }
    void  Triple::show_info() {
        Figura::show_info();
    }

    Triple::Triple(int a, int b, int c, int A, int B, int C, std::string name) : Figura(3, name) {
        if ((A + B + C) != 180) {
            throw Bad_figure(Figura::name + " ( стороны " + std::to_string(a) + ", " + std::to_string(b) + ", " + std::to_string(c) + "; углы " + std::to_string(A) +
                ", " + std::to_string(B) + ", " + std::to_string(C) +")"+ Triple::check());
        }
        this->a = a, this->b = b, this->c = c, this->A = A, this->B = B, this->C = C;
    }
    void  Triple::print_sides()  {
        std::cout << "(" << stor << " " << " " << "a=" << a << " " << "b=" << b << " " << "c=" << c << "; ";

    }
    void  Triple::print_angles()  {
        std::cout << angle << " " << " " << "A=" << A << " " << "B=" << B << " " << "C=" << C << ") ";
    }
    std::string   Triple::check()  {
        if (number_stor == 3 && (A + B + C) == 180)
            return " Создана";
        else
            return  " Не создана. Причина: сумма углов не равна 180 ";

    }

  


