#pragma once

#include <string>
class Figura {
public:

    void print();






protected:
    std::string stor = "�������";
    std::string angle = "����";
    std::string name;
    int number_stor= 0;
    std::string states;

    Figura(int number_stor, std::string name);

    virtual void print_sides();
    virtual void print_angles();
    virtual void show_info();
    virtual bool check();
   

};