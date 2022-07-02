﻿#include "Figura.h"
#include "Four.h"
#include "Paralelogram.h"
#include "Pramoug.h"
#include  "quad.h"
#include "Romb.h"
#include "Exception.h"
#include <sstream>





  
   Four::Four(int a, int b, int c, int d, int A, int B, int C, int D) : Figura(4, "Четырехугольник"), a(a),b(b),c(c),d(d),A(A),B(B),C(C),D(D) {
       check();
        
    }
   
      std::string Four::print_info() const {
       std::stringstream f;
       f << Figura::print_info();
       f << "(" << stor << " " << " " << "a=" << a << " " << "b=" << b << " " << "c=" << c << " " << "d=" << d << "; ";
       f << angle << " " << " " << "A=" << A << " " << "B=" << B << " " << "C=" << C << " " << "D=" << D << ") ";
       
       return f.str();


   }
    
     std::string Four::check() const  {
         
         if (number_stor == 4 && (A + B + C + D) == 360)
             return print_info()+" Создана \n";
         else if (Figura::number_stor != 4) {
             return print_info() + " Не создана. Причина: количество сторон не равно 4 \n";
         }
         else
             return print_info() + " Не создана. Причина: сумма углов не равна 360 \n";
         if (Figura::name == "Паралелограм"|| Figura::name == "Ромб") {
             if (a != c || b != d) {
                 return print_info() + " Не создана. Причина: Стороны попарно не равны \n";
             }
             else if   (A != C || B != D) {
                 return print_info() + " Не создана. Причина: Углы попарно не равны \n";
             }
         }
         
         else if(Figura::name=="Прямоугольник" || Figura::name == "Квадрат")
             if (a != c || b != d) {
                 return print_info() + " Не создана. Причина: Стороны попарно не равны \n";
             }
             else if ((A==B==C==D)!=90) {
                 return print_info() + " Не создана. Причина: Углы  не равны 90 \n";
             }
         
         

    }


    Four::Four(int a, int b, int A, int B, std::string name) : Figura(4, name), a(a), b(b), c(a), d(b), A(A), B(B), C(A), D(B) {
        check();
        
    }

   