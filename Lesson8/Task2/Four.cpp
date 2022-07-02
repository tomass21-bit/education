#include "Figura.h"
#include "Four.h"
#include "Paralelogram.h"
#include "Pramoug.h"
#include  "quad.h"
#include "Romb.h"
#include "Exception.h"
#include <sstream>





  
   Four::Four(int a, int b, int c, int d, int A, int B, int C, int D) : Figura(4, "Четырехугольник"), a(a),b(b),c(c),d(d),A(A),B(B),C(C),D(D) {
       
        if (Figura::number_stor != 4) {
           throw Bad_figure(print_info());
       }
       else if ((A + B + C + D) != 360) {
            throw Bad_figure(print_info());
       }
           
       
        
    }
   
      std::string Four::print_info() const {
       std::stringstream f;
       f << Figura::print_info();
       f << "(" << stor << " " << " " << "a=" << a << " " << "b=" << b << " " << "c=" << c << " " << "d=" << d << "; ";
       f << angle << " " << " " << "A=" << A << " " << "B=" << B << " " << "C=" << C << " " << "D=" << D << ") ";
       f << Four::check();
       return f.str();


   }
    
     std::string Four::check() const  {
         
         
         if (Figura::name == "Паралелограм"|| Figura::name == "Ромб") {
             if (a != c || b != d) {
                 return   " Не создана. Причина: Стороны попарно не равны \n";
             }
             else if   (A != C || B != D) {
                 return   " Не создана. Причина: Углы попарно не равны \n";
             }
         }
         
         else if(Figura::name=="Прямоугольник" || Figura::name == "Квадрат")
             if (a != c || b != d) {
                 return   " Не создана. Причина: Стороны попарно не равны \n";
             }
             else if (A!=B || B != C || C==D && A!=90) {
                 return   " Не создана. Причина: Углы  не равны 90 \n";
             }
         if (Figura::number_stor == 4 && (A + B + C + D) == 360)
             return  " Создана \n";
         else if (Figura::number_stor != 4) {
             return   " Не создана. Причина: количество сторон не равно 4 \n";
         }
         else if ((A + B + C + D) != 360)
             return  " Не создана. Причина: сумма углов не равна 360 \n";
         

    }


    Four::Four(int a, int b, int A, int B, std::string name) : Figura(4, name), a(a), b(b), c(a), d(b), A(A), B(B), C(A), D(B) {
        if (Figura::number_stor != 4) {
            throw Bad_figure(print_info());
        }
        else if ((Four::A + Four::B + Four::C + Four::D) != 360) {
            throw Bad_figure(print_info());
        }

        if (Figura::name == "Паралелограм" || Figura::name == "Ромб") {
            if (Four::a != Four::c || Four::b != Four::d) {
                throw Bad_figure(print_info());
            }
            else if (Four::A != Four::C || Four::B != Four::D) {
                throw Bad_figure(print_info());
            }
        }

        else if (Figura::name == "Прямоугольник" || Figura::name == "Квадрат")
            if (Four::a != Four::c || Four::b != Four::d) {
                throw Bad_figure(print_info());
            }
            else if (Four::A != Four::B || Four::B != Four::C || Four::C == Four::D && Four::A != 90) {
                throw Bad_figure(print_info());
            }
        
    }

   