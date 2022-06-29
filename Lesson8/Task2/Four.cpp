#include "Figura.h"
#include "Four.h"
#include "Paralelogram.h"
#include "Pramoug.h"
#include  "quad.h"
#include "Romb.h"
#include "Exception.h"





  
   Four::Four(int a, int b, int c, int d, int A, int B, int C, int D) : Figura(4, "Четырехугольник") {
       if ((A + B + C + D) != 360) {
           throw Bad_figure(Figura::name+ " ( стороны " + std::to_string(a)+", " +std::to_string(b) + ", " +std::to_string(c) + ", "
               +std::to_string(d) + "; углы " + std::to_string(A) + ", " + std::to_string(B) + ", " + std::to_string(C) + ", " +std::to_string(D)+ ")" + Four::check( ));
       }
        this->a = a, this->b = b, this->c = c, this->d = d, this->A = A, this->B = B, this->C = C, this->D = D;
    }
   void Four::show_info()   {
        Figura::show_info();
    }

    void Four::print_sides()  {

        std::cout <<"(" << stor << " " << " " << "a=" << a << " " << "b=" << b << " " << "c=" << c << " " << "d=" << d << "; ";
    }


    void Four::print_angles()  {
        std::cout << angle << " " << " " << "A=" << A << " " << "B=" << B << " " << "C=" << C << " " << "D=" << D << ") ";

    }
     std::string Four::check()  {
         if (number_stor == 4 && (A + B + C + D) == 360)
             return " Создана";
         else
             return  " Не создана. Причина: сумма углов не равна 360 ";

    }


    Four::Four(int a, int b, int A, int B, std::string name) : Figura(4, name) {
        if (((A + B)*2 ) != 360) {
            throw Bad_figure(Figura::name + " ( стороны " + std::to_string(a) + ", " + std::to_string(b) + ", " + std::to_string(a) + ", "
                + std::to_string(b) + "; углы " + std::to_string(A) + ", " + std::to_string(B) + ", " + std::to_string(A) + ", " + std::to_string(B) + ")" + Four::check() );
        }
        this->a = a, this->b = b, this->c = a, this->d = b, this->A = A, this->B = B, this->C = A, this->D = B;
    }

   