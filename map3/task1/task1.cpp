// task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <list>
#include <thread>
#include <future>


std::list<int>::iterator serch( std::list<int>& list, std::list<int>::iterator begin, std::list<int>::iterator end) {
    
    int temp = *begin;
    std::list<int>::iterator it =begin;
    for (begin; begin != end; begin++) {
        if (temp > *begin) {
            temp = *begin;
            it = begin;
        }
    }
    return it;
}

void sort_vib(std::list<int>& list, std::promise<void> flag) {
    std::list<int>::iterator begin= list.begin();
    std::list<int>::iterator end = list.end();
    end;
    for (begin; begin != end; begin++) {
        auto it = std::async(serch, std::ref(list) ,begin,end);
        std::swap(*begin, *it.get());
        
    }
    flag.set_value();
}


int main()
{
    std::list<int> list = { 5,7,2,9,12,4,3,7,1,8,13,11,19,17 };
    std::promise<void> flag;
    std::future<void> flag_future = flag.get_future();
    std::thread thr(sort_vib, std::ref(list), std::move(flag));
    flag_future.wait();
    thr.join();
    for (auto t : list) {
        std::cout << t << " ";
    }
   
    return 0;
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
