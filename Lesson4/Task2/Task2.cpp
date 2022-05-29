// Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
#include <clocale>
#include <iomanip>


class adress {
public:
    std::string city;
    void write_file() {

        std::ofstream fout("out.txt", std::ios_base::app);
        fout << city << ", ";
        fout << street << ", ";
        fout << number_house << ", ";
        fout << number_flat << std::endl;
        fout.close();

    }
   
    adress(std::string city, std::string street, int number_house, int number_flat) {
        this->city = city;
        this->street = street;
        this->number_house = number_house;
        this->number_flat = number_flat;
    }
    adress() {
        city = "ucnown";
        street = "ucnown";
        number_house = 0;
        number_flat = 0;
    }

private:
        std::string street;
        int number_house;
        int number_flat;


    
};

void sort(adress* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i].city > arr[j].city) {
                adress temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");
    std::string city;
    std::string street;
    int number_house;
    int number_flat;
    int vol;

    std::string buf;
    std::ifstream fin("in.txt");

    if (fin.is_open()) {

        fin >> buf;
        vol = stoi(buf);
        adress* arr = new adress[vol];

        for (int i = 0; i < vol; ++i) {

            fin >> buf;
            city = buf;
            fin >> buf;
            street = buf;
            fin >> buf;
            try
            {
                number_house = stoi(buf);
            }
            catch (std::invalid_argument)
            {

                std::cout << "Номером дома может быть только чило  \n";
                exit(0);
            }

            catch (...)
            {
                //Если будет выброшено какое-то исключение, которое не обработано выше, то говорим, что возникла неизвестная ошибка
                std::cout << "Unknown error! \n";
                exit(0);
            }
            fin >> buf;
            try
            {
                number_flat = stoi(buf);
            }
            catch (std::invalid_argument)
            {

                std::cout << "Номером квартиры может быть только чило  \n";
                exit(0);
            }

            catch (...)
            {
                //Если будет выброшено какое-то исключение, которое не обработано выше, то говорим, что возникла неизвестная ошибка
                std::cout << "Unknown error! \n";
                exit(0);
            }

            arr[i] = adress(city, street, number_house, number_flat);
        }
        fin.close();

        std::ofstream fout("out.txt");
        fout << vol << std::endl;
        sort(arr, vol);
        for (int j = 0; j <vol; ++j)
        {
            arr[j].write_file();
        }

        delete[] arr;
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
