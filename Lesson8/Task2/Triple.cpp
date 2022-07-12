 
#include "Figura.h"
#include "Exception.h"
#include "Triple.h"
#include "Triple_pramoug.h"
#include "Triple_ravnobed.h"
#include "Triple_ravnostor.h"
#include <sstream>



    Triple:: Triple() : Figura(3, "Треугольник") { a = 30, b = 35, c = 50, A = 30, B = 60, C = 70; }
    Triple::Triple(int a, int b, int c, int A, int B, int C) : Figura(3, "Треугольник"), a(a), b(b), c(c), A(A), B(B), C(C) {
        if ((A + B + C) != 180) {
         throw Bad_figure(print_error() + check());
        }
        else if (Figura::number_stor != 3) {
            throw Bad_figure(print_error() + check());
        }
    }
    
    

    std::string Triple::print_info() const {
        std::stringstream i;
        i << Figura::print_info();
        i << "(" << stor << " " << " " << "a=" << a << " " << "b=" << b << " " << "c=" << c <<  "; ";
        i << angle << " " << " " << "A=" << A << " " << "B=" << B << " " << "C=" << C <<  ") ";
        i << check();
        
        return i.str() ;


    }
    std::string Triple::print_error() const {
        std::stringstream e;
        e << Figura::print_info();
        e << "(" << stor << " " << " " << "a=" << a << " " << "b=" << b << " " << "c=" << c << "; ";
        e << angle << " " << " " << "A=" << A << " " << "B=" << B << " " << "C=" << C << ") ";
        return e.str();
    }

    

    Triple::Triple(int a, int b, int c, int A, int B, int C, std::string name) : Figura(3, name), a(a), b(b), c(c), A(A), B(B), C(C) {
        if ((A + B + C) != 180) {
            throw Bad_figure(print_error() + check());
        }
        else if (Figura::number_stor != 3) {
            throw Bad_figure(print_error() + check());
        }
        
    }
   
    std::string   Triple::check()const {
        if (number_stor == 3 && (A + B + C) == 180)
            return " Создана \n";
        else if (Figura::number_stor != 3) {
            return " Не создана. Причина: количество сторон не равно 3 \n";
        }
        else if ((A + B + C) != 180)
            return  " Не создана. Причина: сумма углов не равна 180 \n";

    }

  


