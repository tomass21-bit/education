#include "Figura.h"
#include "Four.h"
#include "Paralelogram.h"
#include "Pramoug.h"
#include  "quad.h"
#include "Romb.h"



Pramoug:: Pramoug() :Paralelogram(20, 40, 90, 90, "Прямоугольник") { }
Pramoug::Pramoug(int a, int b) : Paralelogram(a, b, 90, 90, "Прямоугольник") {  }
    


    Pramoug::Pramoug(int a, std::string name) : Paralelogram(a, a, 90, 90, name) {  }

   

