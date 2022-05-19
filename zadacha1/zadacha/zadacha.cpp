// zadacha.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <clocale>
#include <string>

int main()
{
    setlocale(LC_ALL, "Russian"); // задаём русский текст

    int size1 = 0;
    int size2 = 0;
    std::string buf;
    std::ifstream fin("in.txt");
    if (fin.is_open()) {

        fin >> buf;
        
        size1 = stoi(buf);

        std::string* arr1 = new std::string [size1];

        for (int i = 0; i < size1; i++) {
            fin >> buf;
           
            arr1[i] = buf;

        }

        fin >> buf;
        
        size2 = stoi(buf);

        std::string* arr2 = new std::string[size2];

        for (int k = 0; k < size2; k++) {
            fin >> buf;
            
            arr2[k] = buf;

        }
        fin.close();
        
        std::ofstream fout("out.txt");
        std::string y = std::to_string(size2); //преобразование в строку для вывода в файл
        fout << y << std::endl;
        fout << arr2[size2-1] << " ";
        for (int j = 0; j < size2-1; j++) {
            fout << arr2[j] << " ";
        }
        fout << std::endl;
        std::string z = std::to_string(size1);   //преобразование в строку для вывода в файл
        fout << y << std::endl;
        for (int m = 1; m < size1; m++) {
            fout << arr1[m] << " ";
        }

        fout << arr1[0]<< std::endl;
        fout.close();



        

        delete[] arr1;
        delete[] arr2;





    }
    else
        std::cout << "Файл не найден" << std::endl;
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
