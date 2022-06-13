#pragma once
#include <iostream>
#include <string>
class Triple : public Figura {
public:
    void show_info() override;
    
    void get_parametrs();

    Triple() : Figura(3, 20, 30, 40, 65, 80, 45, "Треугольник");
protected:
    Triple(int a, int b, int c, int A, int B, int C, std::string name) : Figura(3, a, b, c, A, B, C, name);

    }
bool check(int number_stor) override;
};