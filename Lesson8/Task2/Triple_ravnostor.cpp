#include "Figura.h"
#include "Exception.h"
#include "Triple.h"
#include "Triple_pramoug.h"
#include "Triple_ravnobed.h"
#include "Triple_ravnostor.h"
#include <sstream>



   


    Triple_ravnostor::Triple_ravnostor() : Triple(20, 20, 20, 60, 60, 60, "Равнобедренный треугольник") { }
    Triple_ravnostor::Triple_ravnostor(int a) : Triple(a, a, a, 60, 60, 60, "Равноcторонний треугольник") {

        check();


    }
    

    void  Triple_ravnostor::check()const {


      
       if (a != b || b != c) {
           throw Bad_figure(Triple_ravnostor::print_error() + " Не создана. Причина: Стороны не равны \n");
       }
       else if (A != B || B != C) {
           throw Bad_figure(Triple_ravnostor::print_error() + " Не создана. Причина: Углы не равны \n");
       }

    }
    
    
