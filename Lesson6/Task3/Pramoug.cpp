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


Pramoug:: Pramoug() :Paralelogram(20, 40, 90, 90, "Прямоугольник") { }
Pramoug::Pramoug(int a, int b) : Paralelogram(a, b, 90, 90, "Прямоугольник") {  }
    void Pramoug::show_info()  
    {
        Figura::show_info();
    }


    Pramoug::Pramoug(int a, std::string name) : Paralelogram(a, a, 90, 90, name) {  }

    bool Pramoug::check()  {

        if (Paralelogram::check() == true && A == B && C == D)
            return true;
        else
            return false;

    }

