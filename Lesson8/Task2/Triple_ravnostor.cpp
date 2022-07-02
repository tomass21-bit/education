#include "Figura.h"
#include "Exception.h"
#include "Triple.h"
#include "Triple_pramoug.h"
#include "Triple_ravnobed.h"
#include "Triple_ravnostor.h"
#include <sstream>



   


    Triple_ravnostor::Triple_ravnostor() : Triple(20, 20, 20, 60, 60, 60, "Равнобедренный треугольник") { }
    Triple_ravnostor::Triple_ravnostor(int a) : Triple(a, a, a, 50, 60, 60, "Равноcторонний треугольник") {
        if (Triple::a!= Triple::b|| Triple::b != Triple::c) {
            throw Bad_figure(Triple::print_info() + check());
        }
        else if (Triple::A != 60 || Triple::B != 60 || Triple::C != 60) {
            throw Bad_figure(Triple::print_info() + check());
        }
    }

   
    
    std::string Triple_ravnostor::check() const {
        if (a != b != c) {
            return  " Не создана. Причина: Стороны не равны \n";
        }
        else if (A != 60 || B != 60 || C != 60) {
            return  " Не создана. Причина: Углы не равны 60 \n";
        }
       

    }
