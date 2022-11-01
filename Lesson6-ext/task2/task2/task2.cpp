// task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>

template <class T>
class Table 
{
public:
    Table( int x,  int y) : rows(x), cols(y) {
         arr = new T* [x];
        for (int i = 0; i <x; i++) {
            arr[i] = new T[y];
        }

    }
    ~Table() {
        for (int i = 0; i < rows; i++) {
           
            delete[] arr[i];
        }
        delete[] arr;
    }
    Table(const Table& t) {
       T** arr = new T* [t.rows];
        for (int i = 0; i < t.rows; i++) {
             arr[i] = new T[t.cols];
        }
        for (int j = 0; j < t.rows; j++) {
            for (int k = 0; k < t.cols; k++) {
                arr[j][k] = t.arr[j][k];
            }

        }
       
        
    }

    
      T* operator[] (int index) const {

        return arr[index];
    }
     T* operator[] (int index) {
        return arr[index];
    }
    
    
     Table& operator = (const Table& ar) {
         if (this == &ar) {
             return *this;
         }
         else
          if(rows>0 && cols>0)
              for (int i = 0; i < rows; i++) {

                  delete[] arr[i];
              }
         delete[] arr;
         rows = ar.rows;
         cols = ar.cols;
          arr = new T * [rows];
         for (int i = 0; i < rows; i++) {
             arr[i] = new T[cols];
         }
         for (int j = 0; j < rows; j++) {
             for (int k = 0; k < cols; k++) {
                 arr[j][k] = ar.arr[j][k];
             }

         }

              
         
         
         return *this;
     }
     void size() const {
         std::cout << "Строки: " << this->rows << std::endl << "Столбцы: " << this->cols << std::endl;
    }


protected:
    int rows=0;
    int cols=0;
    T** arr=nullptr ;
};
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    auto test = Table<int>(2, 3);
    test[0][0] = 4;
    
    std::cout << test[0][0]<< std::endl;
    test.size();
    
    auto test2 = Table<int>(2, 3);
    test2[1][2] = 2;

    test = test2;
    std::cout << test[1][2];
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
