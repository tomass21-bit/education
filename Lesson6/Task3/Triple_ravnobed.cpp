#include "Figura.h"
//#include "Four.h"
//#include "Paralelogram.h"
//#include "Pramoug.h"
//#include  "quad.h"
//#include "Romb.h"
#include "Triple.h"
#include "Triple_pramoug.h"
#include "Triple_ravnobed.h"
#include "Triple_ravnostor.h"

#include <string>


    void Triple_ravnobed:: show_info() 
    {
        Figura::show_info();
    }

    Triple_ravnobed::Triple_ravnobed() : Triple(20, 40, 20, 50, 70, 30, "�������������� �����������") {  }
    Triple_ravnobed::Triple_ravnobed(int a, int b, int A, int B) : Triple(a, b, a, A, B, A, "�������������� �����������") {  }

    bool Triple_ravnobed::check()   {

        if (Triple::check() == true && a == c && A == C)
            return true;
        else
            return false;

    }

