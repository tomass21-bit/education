// task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

int multiplication(int i) {
    i *= 10;
    return i;
}


void for_each_t(std::vector<int>::iterator begin, std::vector<int>::iterator end, int(&f)(int)) {
    
    auto step = std::distance(begin, end);
    
    if (step > 2500) {
            step /= 2;
            std::async(&for_each_t,begin, end - step, std::ref(f));
            for_each_t( begin+step, end, f);
    }
    else
        for (begin; begin != end; begin++) {
            int a = f(*begin);
            *begin = a;
        }
   
  return;
}

void set_random(std::vector<int>& v) {
    std::mt19937 gen;
    std::uniform_int_distribution<int> dis(0, 1000);
    auto rand_num([=]() mutable { return dis(gen); });
    std::generate(begin(v), end(v), rand_num);
}
int main()
{
    std::vector<int> vec(1'000'000);
    std::vector<int> vec2(1'000'000);
    set_random(vec);
    set_random(vec2);
    auto start1 = std::chrono::high_resolution_clock::now();
    for_each(vec2.begin(), vec2.end(), multiplication);
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> times1 = end1 - start1;
    auto time1=times1.count();

    auto start2 = std::chrono::high_resolution_clock::now();
    for_each_t( vec.begin(), vec.end() , multiplication);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> times2 = end2 - start2;
    auto time2 = times2.count();
    std::cout << "standart " << time1 << " \t" << "multithread " << time2;
    /*for (auto t : vec) {
        std::cout << t << " ";
    }*/
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
