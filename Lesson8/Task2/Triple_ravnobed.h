#pragma once
#include <iostream>
#include <string>
class Triple_ravnobed : public Triple
{
public:
   
    Triple_ravnobed();
    Triple_ravnobed(int a, int b, int A, int B);
   

protected:
    
   void   check()const;
};