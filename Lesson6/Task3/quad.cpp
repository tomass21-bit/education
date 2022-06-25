#include "Figura.h"
#include "Four.h"
#include "Paralelogram.h"
#include "Pramoug.h"
#include  "quad.h"
#include "Romb.h"
//#include "Triple.h"
//#include "Triple_pramoug.h"
//#include "Triple_ravnobed.h"

#include <string>


   Quad:: Quad() : Pramoug(20, " вадрат") { }
   Quad::Quad(int a) : Pramoug(a, " вадрат") { }
    void Quad::show_info()  
    {
        Figura::show_info();
    }

    bool  Quad::check()  {

        if (Pramoug::check() == true && (a == b && c == d))
            return true;
        else
            return false;

    }
