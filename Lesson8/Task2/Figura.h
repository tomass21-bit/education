#pragma once

#include <string>

class Figura {
public:

    void print();






protected:
    const std::string stor ="cтороны";
   const std::string angle ="углы";
    std::string name;
    int number_stor= 0;
    std::string states;

    Figura(int number_stor, std::string name);

    virtual void print_sides();
    virtual void print_angles();
    virtual void show_info();
    virtual bool check();
    void names();
   

};