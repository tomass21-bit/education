// task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

template <class T>
class Table
{
public:
    Table(const int& x, const int& y) : rows(x), cols(y) {
        T** arr = new T * [x];
        for (int i = 0; i < x; i++) {
            arr[i] = new T[y];
        }

    }
    ~Table() {
        for (int i = 0; i < rows; i++) {
            arr[i] = new T[cols];
            delete[] arr[i];
        }
        delete[] arr;
    }

    void   size() {
        std::cout << "строки: " << rows << std::endl;
        std::cout << "столбцы: " << cols << std::endl;
    }
    const Table operator[] (int index) const {
        return ptr [index][index];
    }
     Table operator[] (int index) {
        return arr[index];
    }
     Table& operator = (const int& value) {
         
     }



protected:
    int rows=0;
    int cols=0;
    T* arr = nullptr;
};
int main()
{
    auto test = Table<int>(2, 3);
    test[0][0] = 4;
    /*std::cout << test[0][0];*/
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
