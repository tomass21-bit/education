// search.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <stdio.h> 
#include <direct.h>




class Search_str {
public:
    Search_str(const std::string& s, const std::string& e): str(s), extension(e) {

    }
    ~Search_str() {
        str.clear();
    }
    
    std::string get_ext() {
        return extension;
    }
private:

    std::string extension;
    std::string str;
    std::string pars;
    
};
class Search_file:public Search_str {
public:
    void set_files(const std::string& path) {
        for (const auto& file : std::filesystem::directory_iterator(path)) {
            if (std::filesystem::is_directory(file)) {
                set_files(file.path().string());
            }
            else {
                if ((file.path().filename().string()).find(Search_str::get_ext()) != std::wstring::npos) {
                    files.push_back(file.path().string());
                }
            }
        }
    }
    
private:
    
    std::vector<std::string> files; 
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
