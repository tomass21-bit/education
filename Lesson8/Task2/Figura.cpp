#include "Figura.h"
#include "Exception.h"
#include <iostream>
#include <string>






     void Figura:: print() {
        names();
        print_sides();
        print_angles();
        show_info();
    }
     Figura::Figura(int number_stor, std::string name) {
        
        
         this->number_stor = number_stor, this->name = name;
    }
    
     void Figura::print_sides() {}
     void Figura::print_angles() {}
     void Figura::names(){
         std::cout << name << " ";
     }
     void Figura::show_info() {
         std::cout << "Создана" << std::endl;
        
        
    }
   std::string Figura::check() {
        if (number_stor == 0)
            return " Создана";
        else
            return  " Не создана. Причина: количество сторон не равно 0 ";
    }
