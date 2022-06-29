#include "Figura.h"
#include "Four.h"
#include "Paralelogram.h"
#include "Pramoug.h"
#include  "quad.h"
#include "Romb.h"



   Quad:: Quad() : Pramoug(20, " Квадрат") { }
   Quad::Quad(int a) : Pramoug(a, " Квадрат") { }
    void Quad::show_info()  
    {
        Figura::show_info();
    }

   
