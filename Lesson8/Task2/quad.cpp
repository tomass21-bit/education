#include "Figura.h"
#include "Four.h"
#include "Paralelogram.h"
#include "Pramoug.h"
#include  "quad.h"
#include "Romb.h"
#include "Exception.h"


   Quad:: Quad() : Pramoug(20, " Квадрат") { }
   Quad::Quad(int a) : Pramoug(a, " Квадрат") {
       check();
   }
    
   void Quad::check() const {

       if (a != c || b != d) {
           throw Bad_figure(Quad::print_error() + " Не создана. Причина: Стороны попарно не равны \n");
       }
       else if (A != B || B != C || C == D && A != 90) {
           throw Bad_figure(Quad::print_error() + " Не создана. Причина: Углы  не равны 90 \n");
       }

   }