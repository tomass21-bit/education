﻿#pragma once
#include <iostream>
#include <string>
#include "Figura.h"
class Triple : public Figura {
public:
    Triple();
    Triple(int a, int b, int c, int A, int B, int C);
    
    std::string print_info() const override;
    
protected:
    Triple(int a, int b, int c, int A, int B, int C, std::string name);
     std::string print_error() const;
     std::string check()const;
   

    int a=0;
    int b=0;
    int c=0;
    int A=0;
    int B=0;
    int C=0;

};