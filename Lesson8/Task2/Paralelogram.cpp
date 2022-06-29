#include "Figura.h"
#include "Four.h"
#include "Paralelogram.h"
#include "Pramoug.h"
#include  "quad.h"
#include "Romb.h"



Paralelogram::Paralelogram() :Four(20, 25, 120, 60, "Паралелограм") { }
Paralelogram::Paralelogram(int a, int b, int A, int B) : Four(a, b, A, B, "Паралелограм") {  }
    void Paralelogram::show_info() 
    {
        Figura::show_info();
    }

    Paralelogram::Paralelogram(int a, int b, int A, int B, std::string name) : Four(a, b, A, B, name) {  }

    
