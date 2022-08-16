
#include "Figura.h"
#include <iostream>
#include <string>





   
     void  Figura:: print() {
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
