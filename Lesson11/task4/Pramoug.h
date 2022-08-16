#pragma once

#include <iostream>
#include <string>
class Pramoug : public Paralelogram
{
public:

    Pramoug();
    Pramoug(int a, int b);
    void show_info() override;

protected:
    Pramoug(int a, std::string name);

    bool check() override;

};