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

    
    double sum_vectors( unsigned begin_v,const unsigned end_v ) {
        auto start = std::chrono::high_resolution_clock::now();
        
                for ( begin_v ; begin_v < end_v; ++begin_v)
                {
                    res[begin_v] = a1[begin_v] + a2[begin_v];
                }
            
        

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time = end - start;
        return time.count();
        
    }

    
    int size = 0;
    int size2 = size / 2;
    int size4 = size / 4;
    int size8 = size / 8;
    int size16 = size / 16;
    

protected:
    std::vector<int> a1;
    std::vector<int> a2;
    std::vector<int> res;
    
    
    void set_random(std::vector<int>& v) {
        std::mt19937 gen;
        std::uniform_int_distribution<int> dis(0, 1000);
        auto rand_num([=]() mutable { return dis(gen); });
        std::generate(begin(v), end(v), rand_num);
    }



};

struct Data {

};








int main()
{
    setlocale(LC_ALL, "RU");
    std::cout << "Количество аппаратных ядер - " << std::thread::hardware_concurrency() << std::endl;
    double time_2p1 = 0.0;
    double time_2p2 = 0.0;
    double time_2p3 = 0.0;
    double time_2p4 = 0.0;
    double time_4p1 = 0.0;
    double time_4p2 = 0.0;
    double time_4p3 = 0.0;
    double time_4p4 = 0.0;
    double time_8p1 = 0.0;
    double time_8p2 = 0.0;
    double time_8p3 = 0.0;
    double time_8p4 = 0.0;
    double time_16p1 = 0.0;
    double time_16p2 = 0.0;
    double time_16p3 = 0.0;
    double time_16p4 = 0.0;
    

   //Создание обектов
    Sum_vector t1(1000);
    Sum_vector t2(10'000);
    Sum_vector t3(100'000);
    Sum_vector t4(1000'000);
   
    std::cout << "\t"  << t1.size << "\t" << t2.size << "\t" << t3.size << "\t" << t4.size << std::endl; //Вывод количества элементов

    // Запуск 1 потока
    std::cout << "1 потока " << t1.sum_vectors(0, t1.size) <<"\t"
     << t2.sum_vectors(0, t2.size) << "\t"
     << t3.sum_vectors(0, t3.size) <<"\t"
     << t4.sum_vectors(0, t4.size) << std::endl;
  
    // Запуск 2 потоков
    std::thread p1([&t1,&time_2p1](){
        time_2p1 += t1.sum_vectors(0, t1.size/2);   });
    std::thread p2([&t1, &time_2p1]() {
        time_2p1 += t1.sum_vectors(t1.size / 2, t1.size); });
    p1.join();
    p2.join();

    std::thread p7([&t2, &time_2p2]() {
       time_2p2 += t2.sum_vectors(0, t2.size / 2);   });
    std::thread p8([&t2, &time_2p2]() {
        time_2p2 += t2.sum_vectors(t2.size / 2, t2.size); });
    p7.join();
    p8.join();


    std::thread p3([&t3, &time_2p3]() {
       time_2p3 += t3.sum_vectors(0, t3.size / 2);   });
    std::thread p4([&t3, &time_2p3]() {
        time_2p3 += t3.sum_vectors(t3.size / 2, t3.size); });
    p3.join();
    p4.join();

    std::thread p5([&t4, &time_2p4]() {
        time_2p4 += t4.sum_vectors(0, t4.size / 2);   });
    std::thread p6([&t4, &time_2p4]() {
       time_2p4 += t4.sum_vectors(t4.size / 2, t4.size); });
    p5.join();
    p6.join();

    //Запуск 4 потока
    std::thread pt41([&t1, &time_4p1]() {
        time_4p1 += t1.sum_vectors(0, t1.size / 4);   });
    std::thread pt42([&t1, &time_4p1]() {
        time_4p1 += t1.sum_vectors(t1.size / 4, t1.size/2); });
    std::thread pt43([&t1, &time_4p1]() {
        time_4p1 += t1.sum_vectors( t1.size / 2, t1.size / 4*3);   });
    std::thread pt44([&t1, &time_4p1]() {
        time_4p1 += t1.sum_vectors(t1.size / 4 * 3 , t1.size); });
    pt41.join();
    pt42.join();
    pt43.join();
    pt44.join();


    std::thread pm41([&t2, &time_4p2]() {
       time_4p2 += t2.sum_vectors(0, t2.size / 4);   });
    std::thread pm42([&t2, &time_4p2]() {
        time_4p2 += t2.sum_vectors(t2.size / 4, t2.size / 2); });
    std::thread pm43([&t2, &time_4p2]() {
        time_4p2 += t2.sum_vectors(t2.size / 2, t2.size / 4 * 3);   });
    std::thread pm44([&t2, &time_4p2]() {
        time_4p2 += t2.sum_vectors(t2.size / 4 * 3, t2.size); });
    pm41.join();
    pm42.join();
    pm43.join();
    pm44.join();


    std::thread ps41([&t3, &time_4p3]() {
        time_4p3 += t3.sum_vectors(0, t3.size / 4);   });
    std::thread ps42([&t3, &time_4p3]() {
        time_4p3 += t3.sum_vectors(t3.size / 4, t3.size / 2); });
    std::thread ps43([&t3, &time_4p3]() {
        time_4p3 += t3.sum_vectors(t3.size / 2, t3.size / 4 * 3);   });
    std::thread ps44([&t3, &time_4p3]() {
        time_4p3 += t3.sum_vectors(t3.size / 4 * 3, t3.size); });
    ps41.join();
    ps42.join();
    ps43.join();
    ps44.join();

    std::thread pn41([&t4, &time_4p4]() {
        time_4p4 += t4.sum_vectors(0, t4.size / 4);   });
    std::thread pn42([&t4, &time_4p4]() {
        time_4p4 += t4.sum_vectors(t4.size / 4, t4.size / 2); });
    std::thread pn43([&t4, &time_4p4]() {
        time_4p4 += t4.sum_vectors(t4.size / 2, t4.size / 4 * 3);   });
    std::thread pn44([&t4, &time_4p4]() {
        time_4p4 += t4.sum_vectors(t4.size / 4 * 3, t4.size); });
    pn41.join();
    pn42.join();
    pn43.join();
    pn44.join();

    std::vector <std::thread> thr1; //инициализируем массив потоков 
    unsigned begin8 = 0;
    unsigned end8 = t1.size8;
        // Запуск 8 потоков
    for (unsigned i = 0; i < 8; i++) {
        
            thr1.push_back(std::thread( [&t1, &time_8p1,&begin8,&end8]() {
                time_8p1 += t1.sum_vectors(begin8,end8 );
                begin8 += t1.size8;
                end8 += t1.size8; 
            }));
    }
    for (unsigned j = 0; j < 8; j++) {
        thr1[j].join();
    }
   
    std::vector <std::thread> thr2; //инициализируем массив потоков 
     begin8 = 0;
     end8 = t2.size8;
    
    for (unsigned i = 0; i < 8; i++) {
            thr2.push_back(std::thread([&t2, &time_8p2, &begin8, &end8]() {
            time_8p2 += t2.sum_vectors(begin8, end8);
            begin8 += t2.size8;
            end8 += t2.size8; }));
    }
    for (unsigned j = 0; j < 8; j++) {
        thr2[j].join();
    }
    std::vector <std::thread> thr3; //инициализируем массив потоков 
     begin8 = 0;
     end8 = t3.size8;
    
    for (unsigned i = 0; i < 8; i++) {
        thr3.push_back(std::thread([&t3, &time_8p3, &begin8, &end8]() {
            time_8p3 += t3.sum_vectors(begin8, end8);
            begin8 += t3.size8;
            end8 += t3.size8; 
        }));
    }
    for (unsigned j = 0; j < 8; j++) {
        thr3[j].join();
    }

    std::vector <std::thread> thr4; //инициализируем массив потоков 
     begin8 = 0;
     end8 = t4.size8;
   
    for (unsigned i = 0; i < 8; i++) {

        thr4.push_back(std::thread([&t4, &time_8p4, &begin8, &end8]() {
            time_8p4 += t4.sum_vectors(begin8, end8);
            begin8 += t4.size8;
            end8 += t4.size8; }));
    }
    for (unsigned j = 0; j < 8; j++) {
        thr4[j].join();
    }
    //16 потоков

    std::vector <std::thread> thr5; //инициализируем массив потоков 
    unsigned begin16 = 0;
    unsigned end16 = t1.size16;
    
    for (unsigned i = 0; i < 16; i++) {

        thr5.push_back(std::thread([&t1, &time_16p1, &begin16, &end16]() {
            time_16p1 += t1.sum_vectors(begin16, end16);
            begin16 += t1.size16;
            end16 += t1.size16; }));


    }
    for (unsigned j = 0; j < 16; j++) {
        thr5[j].join();
    }

    std::vector <std::thread> thr6; //инициализируем массив потоков 
    begin16 = 0;
    end16 = t2.size16;

    for (int i = 0; i < 16; i++) {

        thr6.push_back(std::thread([&t2, &time_16p2, &begin16, &end16]() {
           time_16p2 += t2.sum_vectors(begin16, end16);
          begin16 += t2.size16;
           end16 += t2.size16; }));


    }
    for (int j = 0; j < 16; j++) {
        thr6[j].join();
    }
    std::vector <std::thread> thr7; //инициализируем массив потоков 
    begin16 = 0;
    end16 = t3.size16;

    for (int i = 0; i < 16; i++) {

        thr7.push_back(std::thread([&t3, &time_16p3, &begin16, &end16]() {
            time_16p3 += t3.sum_vectors(begin16, end16);
            begin16 += t3.size16;
            end16 += t3.size16; }));


    }
    for (int j = 0; j < 16; j++) {
        thr7[j].join();
    }

    std::vector <std::thread> thr8; //инициализируем массив потоков 
    begin16 = 0;
    end16 = t4.size16;
    for (int i = 0; i < 16; i++) {

        thr8.push_back(std::thread([&t4, &time_16p4, &begin16, &end16]() {
            time_16p4 += t4.sum_vectors(begin16, end16);
            begin16 += t4.size16;
            end16 += t4.size16; }));
    }
    for (int j = 0; j < 16; j++) {
        thr8[j].join();
    }
    
    
    
    
    
    std::cout << "2 потоков " << time_2p1 << "\t" <<  time_2p2 << "\t" << time_2p3 << "\t" << time_2p4 << "\t"  << std::endl;
    std::cout << "4 потоков " << time_4p1 << "\t" << time_4p2 << "\t" << time_4p3 << "\t" << time_4p4 << "\t" << std::endl;
    std::cout << "8 потоков " << time_8p1 << "\t" << time_8p2 << "\t" << time_8p3 << "\t" << time_8p4 << "\t" << std::endl;
    std::cout << "16 потоков " << time_16p1 << "\t" << time_16p2 << "\t" << time_16p3 << "\t" << time_16p4 << "\t" << std::endl;

    
    


   

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
