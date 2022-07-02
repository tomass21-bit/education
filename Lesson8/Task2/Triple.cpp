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
         throw Bad_figure( print_info()  );
        }
        else if (Figura::number_stor != 3) {
            throw Bad_figure(print_info() );
        }
        if (Figura::name == "Прямоугольный треугольник") {
            if (C != 90) {
                throw Bad_figure(print_info());
            }

        }

        else if (Figura::name == "Равнобедренный треугольник")
            if (a != b) {
                throw Bad_figure(print_info());
            }
            else if (A != C) {
                throw Bad_figure(print_info());
            }
        else if (Figura::name == "Равносторонний треугольник")
            if (a != b || b != c) {
                throw Bad_figure(print_info());
            }
            else if (A != B || B != C) {
                throw Bad_figure(print_info());
            }

        
    
    }
    
    std::string Triple::print_info() const {
        std::stringstream f;
        f << Figura::print_info();
        f << "(" << stor << " " << " " << "a=" << a << " " << "b=" << b << " " << "c=" << c <<  "; ";
        f << angle << " " << " " << "A=" << A << " " << "B=" << B << " " << "C=" << C <<  ") ";
        f << check();
        return f.str();


    }

    Triple::Triple(int a, int b, int c, int A, int B, int C, std::string name) : Figura(3, name), a(a), b(b), c(c), A(A), B(B), C(C) {
        if ((A + B + C) != 180) {
            throw Bad_figure( print_info() );
        }
        else if (Figura::number_stor != 3) {
            throw Bad_figure(print_info() );
        }
        
    }
   
    std::string   Triple::check()const {
        if (Figura::name == "Прямоугольный треугольник" ) {
            if ( C!=90) {
                return   " Не создана. Причина: Угол С не равен 90  \n";
            }
            
        }

        else if (Figura::name == "Равнобедренный треугольник" )
            if (a != b) {
                return   " Не создана. Причина: Стороны a и b не равны \n";
            }
            else if (A !=C ) {
                return   " Не создана. Причина: Углы  A и C не равны \n";
            }
        else if (Figura::name == "Равносторонний треугольник")
                if (a != b || b!=c ) {
                    return   " Не создана. Причина: Стороны не равны \n";
                }
                else if (A != B || B!=C ) {
                    return   " Не создана. Причина: Углы не равны \n";
                }
         
        if (number_stor == 3 && (A + B + C) == 180)
            return " Создана \n";
        else if (Figura::number_stor != 3) {
            return " Не создана. Причина: количество сторон не равно 3 \n";
        }
        else if ((A + B + C) != 180)
            return  " Не создана. Причина: сумма углов не равна 180 \n";

    }

  


