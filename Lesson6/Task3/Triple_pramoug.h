#pragma once
#include <iostream>
#include <string>
class Triple_pramoug : public Triple
{
public:
    void show_info() override;

    Triple_pramoug();
    Triple_pramoug(int a, int b, int c, int A, int B);

protected:

    bool check() override;
};