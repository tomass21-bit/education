#pragma once
#include <iostream>
#include <string>
class Romb : public Paralelogram
{
public:

    Romb();
    Romb(int a, int A, int B);
    void show_info() override;
protected:
    
};