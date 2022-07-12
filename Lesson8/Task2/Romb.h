#pragma once
#include <iostream>
#include <string>
class Romb : public Paralelogram
{
public:

    Romb();
    Romb(int a, int A, int B);
    
protected:
    void check() const;
};