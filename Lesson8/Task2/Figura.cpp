#include "Figura.h"
#include "Exception.h"
#include <iostream>
#include <string>
#include <sstream>






     
     std::string Figura::print_info() const  {
         std::stringstream f;
         f << name <<" ";
        
         return  f.str() ;
     }
     Figura::Figura(int number_stor, std::string name) {
         if (Figura::name == "Фигура" && number_stor != 0) {
             
                 throw Bad_figure(print_info()+check());
             

         }
        
         this->number_stor = number_stor, this->name = name;
    }
    
    
   std::string Figura::check()const {
        if (number_stor == 0)
            return " Создана";
        else
            return  " Не создана. Причина: количество сторон не равно 0 ";
    }
