#include "Figura.h"
#include "Four.h"
#include "Paralelogram.h"
#include "Pramoug.h"
#include  "quad.h"
#include "Romb.h"
//#include "Triple.h"
//#include "Triple_pramoug.h"
//#include "Triple_ravnobed.h"
//#include "Triple_ravnostor.h"

#include <string>


   Romb:: Romb() :Paralelogram(25, 25, 130, 70, "����") { }
   Romb::Romb(int a, int A, int B) : Paralelogram(a, a, A, B, "����") {  }
    void Romb::show_info() 
    {
        Figura::show_info();
    }

    bool Romb::check()  {

        if (Paralelogram::check() == true && a + c == b + d)
            return true;
        else
            return false;

    }
