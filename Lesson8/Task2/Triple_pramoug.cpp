#include "Figura.h"
#include "Exception.h"
#include "Triple.h"
#include "Triple_pramoug.h"
#include "Triple_ravnobed.h"
#include "Triple_ravnostor.h"
#include <sstream>


 

 Triple_pramoug::Triple_pramoug() : Triple(30, 35, 50, 30, 60, 90, "Прямоугольный треугольник") {  }
 Triple_pramoug::Triple_pramoug(int a, int b, int c, int A, int B) : Triple(a, b, c, A, B, 90, "Прямоугольный треугольник"){
     check();
        

     
 }


    
 void   Triple_pramoug::check()const {
     
         if (C != 90) {
             throw Bad_figure(Triple_pramoug::print_error()+ " Не создана. Причина: Угол С не равен 90  \n");
         }

     }
 