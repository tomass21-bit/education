#include "Figura.h"

#include "Triple.h"
#include "Triple_pramoug.h"
#include "Triple_ravnobed.h"
#include "Triple_ravnostor.h"




    void  Triple_ravnostor:: show_info() 
    {
        Figura::show_info();
    }


    Triple_ravnostor::Triple_ravnostor() : Triple(20, 20, 20, 60, 60, 60, "Равнобедренный треугольник") { }
    Triple_ravnostor::Triple_ravnostor(int a) : Triple(a, a, a, 60, 60, 60, "Равноcторонний треугольник") {  }

    
