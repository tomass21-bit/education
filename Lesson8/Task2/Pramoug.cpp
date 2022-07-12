#include "Figura.h"
#include "Four.h"
#include "Paralelogram.h"
#include "Pramoug.h"
#include  "quad.h"
#include "Romb.h"
#include "Exception.h"


Pramoug:: Pramoug() :Paralelogram(20, 40, 90, 90, "Прямоугольник") { }
Pramoug::Pramoug(int a, int b) : Paralelogram(a, b, 90, 90, "Прямоугольник") {
    check();
}
    


    Pramoug::Pramoug(int a, std::string name) : Paralelogram(a, a, 90, 90, name) {
        check();
    }

    void Pramoug::check() const {
        
            if (a != c || b != d) {
                throw Bad_figure(Pramoug::print_error() + " Не создана. Причина: Стороны попарно не равны \n");
            }
            else if (A != B || B != C || C == D && A != 90) {
                throw Bad_figure(Pramoug::print_error() + " Не создана. Причина: Углы  не равны 90 \n");
            }
    }
