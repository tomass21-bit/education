#include "Figura.h"
#include "Exception.h"
#include "Triple.h"
#include "Triple_pramoug.h"
#include "Triple_ravnobed.h"
#include "Triple_ravnostor.h"
#include <sstream>



   

    Triple_ravnobed::Triple_ravnobed() : Triple(20, 40, 20, 50, 70, 30, "Равнобедренный треугольник") {  }
    Triple_ravnobed::Triple_ravnobed(int a, int c, int A, int B) : Triple(a, a, c, A, B, A, "Равнобедренный треугольник") {

        check();


    }
   

    

    void   Triple_ravnobed::check()const {

       
       if (a != b) {
           throw Bad_figure(Triple_ravnobed::print_error() + " Не создана. Причина: Стороны a и b не равны \n");
       }
       else if (A != C) {
           throw Bad_figure(Triple_ravnobed::print_error() + " Не создана. Причина: Углы  A и C не равны \n");
       }

    }