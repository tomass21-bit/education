#include "Figura.h"

#include "Triple.h"
#include "Triple_pramoug.h"
#include "Triple_ravnobed.h"
#include "Triple_ravnostor.h"



 void Triple_pramoug::show_info() 
    {
        Figura::show_info();
    }

 Triple_pramoug::Triple_pramoug() : Triple(30, 35, 50, 30, 60, 90, "������������� �����������") {  }
 Triple_pramoug::Triple_pramoug(int a, int b, int c, int A, int B) : Triple(a, b, c, A, B, 90, "������������� �����������") {  }


    bool Triple_pramoug::check()  {

        if (Triple::check() == true && C == 90)
            return true;
        else
            return false;

    }
