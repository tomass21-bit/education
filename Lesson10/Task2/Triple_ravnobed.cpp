#include "Figura.h"

#include "Triple.h"
#include "Triple_pramoug.h"
#include "Triple_ravnobed.h"
#include "Triple_ravnostor.h"




    void Triple_ravnobed:: show_info() 
    {
        Figura::show_info();
    }

    Triple_ravnobed::Triple_ravnobed() : Triple(20, 40, 20, 50, 70, 30, "Равнобедренный треугольник") {  }
    Triple_ravnobed::Triple_ravnobed(int a, int b, int A, int B) : Triple(a, b, a, A, B, A, "Равнобедренный треугольник") {  }

    bool Triple_ravnobed::check()   {

        if (Triple::check() == true && a == c && A == C)
            return true;
        else
            return false;

    }

