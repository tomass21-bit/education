// task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _USE_MATH_DEFINES
#include<iostream>
#include<thread>
#include <Windows.h> 
#include <chrono>
#include <vector>
#include <execution>
#include <random>
#include <algorithm>

class Sum_vector {
public:
    Sum_vector(int size): size(size) {
        std::vector<int> a1(size);
        std::vector<int> a2(size);
        std::vector<int> res(size);
         this->a1=a1;
         this->a2=a2;
         this->res=res;
        set_random(this->a1);
        set_random(this->a2);
        
    }
    ~Sum_vector() {
        a1.clear();
        a2.clear();
        res.clear();
        
    }
    void sum_vectors(int begin_v,int end_v) {
      for ( begin_v ; begin_v < end_v; ++begin_v)
      {
          
       res[begin_v] = a1[begin_v] + a2[begin_v];
      }         
        
    }
    int get_size() {
        return size;
    }
    private:
    std::vector<int> a1;
    std::vector<int> a2;
    std::vector<int> res;
    int size = 0;
    void set_random(std::vector<int>& v) {
        std::mt19937 gen;
        std::uniform_int_distribution<int> dis(0, 1000);
        auto rand_num([=]() mutable { return dis(gen); });
        std::generate(begin(v), end(v), rand_num);
    }
};



int main()
{
    setlocale(LC_ALL, "RU");
    std::cout << "Количество аппаратных ядер - " << std::thread::hardware_concurrency() << std::endl;
    std::vector<double> times;
  
    //Создание обектов
    std::vector<Sum_vector> obj;
    obj.push_back(Sum_vector(1000));
    obj.push_back(Sum_vector(10000));
    obj.push_back(Sum_vector(100000));
    obj.push_back(Sum_vector(1000000));
   
    for (auto t : obj) {
        std::cout << "\t" << t.get_size();  //Вывод количества элементов}
    }
    std::cout <<  std::endl; 
    
    //создание вектора потоков
    std::vector <std::thread> thr;
    for (auto t : obj) {
        
        
        for (int i = 1; i <= 16; i *= 2) {
            int begin = 0;
            int end = t.get_size() / i;
            int delta = t.get_size() / i;
            if (i == 1) {
                auto start = std::chrono::high_resolution_clock::now();
                thr.push_back(std::thread([&t, &begin, &end]() {
                    t.sum_vectors(begin, end); }));
                    thr[0].join();
                 auto end = std::chrono::high_resolution_clock::now();
                 std::chrono::duration<double,std::milli> time = end - start; 
                 times.push_back(time.count());
                 
                     
                 
                 thr.clear();
            }
            else { 
                auto start = std::chrono::high_resolution_clock::now();
                for (int j = 0; j < i; j++) {
                    thr.push_back(std::thread([&t, &begin, &end, &delta]() {
                        t.sum_vectors(begin, end);
                        begin += delta;
                        end += delta; }));
                    
                }
                for (int th = 0; th < i; th++) {
                    thr[th].join();
                }
                auto end = std::chrono::high_resolution_clock::now();

                std::chrono::duration<double, std::milli> time = end - start;
                times.push_back(time.count());
                
                thr.clear();
            }
        }
    }
    
    
      
    
    std::cout << "1 потоков " << times[0] << "\t" << times[5] << "\t" << times[10] << "\t" << times[15] << "\t" << std::endl;
    std::cout << "2 потоков " << times[1] << "\t" << times[6] << "\t" << times[11] << "\t" << times[16] << "\t" << std::endl;
    std::cout << "4 потоков " << times[2] << "\t" << times[7] << "\t" << times[12] << "\t" << times[17] << "\t" << std::endl;
    std::cout << "8 потоков " << times[3] << "\t" << times[8] << "\t" << times[13] << "\t" << times[18] << "\t" << std::endl;
    std::cout << "16 потоков " << times[4] << "\t" << times[9] << "\t" << times[14] << "\t" << times[19] << "\t" << std::endl;

    
    


   

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
