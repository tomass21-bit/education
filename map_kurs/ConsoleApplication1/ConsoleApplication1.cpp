// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>

class Thread_pool {
public:
    Thread_pool(unsigned int size_pool) {
        pool[size_pool];
        for (unsigned i = 0; i < size_pool; i++) {
            work();
        }

    }
    ~Thread_pool() {
        pool.clear();
    }
    void  work(q){}

protected: 
    void set_notified(bool set) {
        if (set == true) {
            g_notified = true;
        }
        else
            g_notified = false;
    }

private:
    struct Task {
        std::function<void()> f;
        void operator()() { f(); }
    };
    std::vector<std::thread> pool;
    bool                    g_done;
    bool                    g_notified;
    Safe_queue<struct Task> queue_s;


};
template<typename Type>
class Safe_queue :public Thread_pool {
public:

protected:
    void push_s() {
        std::lock(mu);
        queue_fu.push()
            mu.unlock();
    }
    void pop_s() {
        std::lock(mu);
        queue_fu.pop()
            mu.unlock();
    }


private:
    std::queue<Type> queue_fu;
    std::mutex mu;
    std::condition_variable inf;
    bool
};



int main()
{
    std::cout << "Hello World!\n";
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
