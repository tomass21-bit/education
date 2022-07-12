#pragma once

#include <string>

class Figura {
public:

    
   virtual std::string print_info() const ;






protected:
    const std::string stor ="cтороны";
   const std::string angle ="углы";
    std::string name;
    int number_stor= 0;
    std::string states;

    Figura(int number_stor, std::string name);

    
     std::string check() const  ;
    

};