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


Paralelogram::Paralelogram() :Four(20, 25, 120, 60, "������������") { }
Paralelogram::Paralelogram(int a, int b, int A, int B) : Four(a, b, A, B, "������������") {  }
    void Paralelogram::show_info() 
    {
        Figura::show_info();
    }

    Paralelogram::Paralelogram(int a, int b, int A, int B, std::string name) : Four(a, b, A, B, name) {  }

    bool Paralelogram::check()  {

        if (Four::check() == true && A == C && B == D && a == c && b == d)
            return true;
        else
            return false;

    }
