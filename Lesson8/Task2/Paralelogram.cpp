#include "Figura.h"
#include "Four.h"
#include "Paralelogram.h"
#include "Pramoug.h"
#include  "quad.h"
#include "Romb.h"
#include "Exception.h"



Paralelogram::Paralelogram() :Four(20, 25, 120, 60, "Паралелограм") { }
Paralelogram::Paralelogram(int a, int b, int A, int B) : Four(a, b, A, B, "Паралелограм") {
    check();
    
}
    

    Paralelogram::Paralelogram(int a, int b, int A, int B, std::string name) : Four(a, b, A, B, name) {
        check();
    }
    
    
    void Paralelogram::check() const {


       
            if (a != c || b != d) {
                
                throw Bad_figure(Paralelogram::print_error() + " Не создана. Причина: Стороны попарно не равны \n");
            }
            else if (A != C || B != D) {
                throw Bad_figure(Paralelogram::print_error() + " Не создана. Причина: Углы попарно не равны \n");
            }
        

    }