#include "Figura.h"
//#include "Four.h"
//#include "Paralelogram.h"
//#include "Pramoug.h"
//#include "quad.h"
//#include "Romb.h"
//#include "Triple.h"
//#include "Triple_pramoug.h"
//#include "Triple_ravnobed.h"
//#include "Triple_ravnostor.h"
#include <iostream>
#include <string>




//class Four;
//class Triple;

     void Figura:: print() {
        show_info();
        print_sides();
        print_angles();
    }
     Figura::Figura(int number_stor, std::string name) {
        this->number_stor = number_stor, this->name = name;
    }

     void Figura::print_sides() {}
     void Figura::print_angles() {}
     void Figura::show_info() {
        std::cout << name << ": " << std::endl;
        if (check() == true) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Не правильная" << std::endl;
        }
        std::cout << "Количество сторон: " << number_stor << std::endl;
    }
     bool Figura::check() {
        if (number_stor == 0)
            return true;
        else
            return false;
    }
