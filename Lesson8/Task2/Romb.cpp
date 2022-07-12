#include "Figura.h"
#include "Four.h"
#include "Paralelogram.h"
#include "Pramoug.h"
#include  "quad.h"
#include "Romb.h"
#include "Exception.h"


   Romb:: Romb() :Paralelogram(25, 25, 130, 70, "Ромб") { }
   Romb::Romb(int a, int A, int B) : Paralelogram(a, a, A, B, "Ромб") {
       check();
   }
    
   void Romb::check() const {
             
           if (a != c || b != d) {
               throw Bad_figure(Romb::print_error() + " Не создана. Причина: Стороны попарно не равны \n");
           }
           else if (A != C || B != D) {
               throw Bad_figure(Romb::print_error() + " Не создана. Причина: Углы попарно не равны \n");
           }
       

   }
   
