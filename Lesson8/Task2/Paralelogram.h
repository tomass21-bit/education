#pragma once
#include <iostream>
#include <string>
class Paralelogram : public Four
{
public:

    Paralelogram();
    Paralelogram(int a, int b, int A, int B);
   
protected:
    Paralelogram(int a, int b, int A, int B, std::string name);

    
};