// Task3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Figura.h"
#include "Four.h"
#include "Paralelogram.h"
#include "Pramoug.h"
#include "quad.h"
#include "Romb.h"
#include "Triple.h"
#include "Triple_pramoug.h"
#include "Triple_ravnobed.h"
#include "Triple_ravnostor.h"
#include <iostream>
#include <string>
#include <clocale>
#include "Exception.h"






void print(Figura& fig) {
    fig.print();
}







int main()
{
    setlocale(LC_ALL, "Russian");
    


    try {
        
        Triple t(15, 20, 30, 50, 60, 70);
       print(t);
       
       /*Triple_pramoug pr(20, 15, 30, 50, 60);
        print(pr);

        Triple_ravnobed rb(20, 30, 50, 40);
        print(rb);

        Triple_ravnostor rs(10);
        print(rs);*/



        Four f(10, 20, 30, 40, 50, 60, 70, 80);
        print(f);

        /*Pramoug pra(10, 20);
        print(pra);

        Quad q(40);
        print(q);

        Paralelogram par(20, 30, 30, 40);
        print(par);*/

        Romb r(30, 30, 150);
        print(r);
        
    }
    
    catch (const std::exception& te) {
        
        std::cout <<  te.what() << std::endl; }

    catch (...) { std::cout << "Неизвестная ошибка" << std::endl; }
    




}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
