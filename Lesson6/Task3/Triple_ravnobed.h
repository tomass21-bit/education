#pragma once
#include <iostream>
#include <string>
class Triple_ravnobed : public Triple
{
public:
    void show_info() override;

    Triple_ravnobed();
    Triple_ravnobed(int a, int b, int A, int B);
protected:
    bool check() override;

};