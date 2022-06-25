#pragma once
#include <iostream>
#include <string>
class Triple_ravnostor : public Triple
{
public:
    void show_info() override;


    Triple_ravnostor();
    Triple_ravnostor(int a);
protected:
    bool check() override;
};