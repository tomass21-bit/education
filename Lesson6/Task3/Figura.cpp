#include "Figura.h"
#include "Four.h"
#include "Paralelogram.h"
#include "Pramoug.h"
#include "quad.h"
#include "Romb.h"
#include "Triple.h"
#include "Triple_pramoug.h"
#include "Triple_ravnobed.h"
#include "Triple_ravnostor.h"
#include <iostream>
#include <string>
virtual void Figura::show_info() {
    std::cout << name << ": " << std::endl;
    if (check(number_stor) == true) {
        std::cout << "Правильная" << std::endl;
    }
    else {
        std::cout << "Не правильная" << std::endl;
    }
    std::cout << "Количество сторон: " << number_stor << std::endl;
}

virtual bool Figura::check(int number_stor) {
    if (number_stor == 0)
        return true;
    else
        return false;
}

Figura::Figura() {
    a = 0, b = 0, c = 0, d = 0, A = 0, B = 0, C = 0, D = 0, name = "Фигура";
}

Figura::Figura(int number_stor, int a, int b, int c, int d, int A, int B, int C, int D, std::string name) {
    this->number_stor = number_stor, this->a = a, this->b = b, this->c = c, this->d = d, this->A = A, this->B = B, this->C = C, this->D = D, this->name = name;
}
Figura::Figura(int number_stor, int a, int b, int c, int A, int B, int C, std::string name) {
    this->number_stor = number_stor, this->a = a, this->b = b, this->c = c, this->A = A, this->B = B, this->C = C, this->name = name;
}