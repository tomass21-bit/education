// task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
void print_pair(const  std::pair<char, int>& m)
{ std::cout << m.first << ": " << m.second <<std::endl;
}

int main()
{
    std::unordered_map< char, int> leng;
    std::string temp;
   
    std::unordered_multiset<char> word;
    std::cout << "IN: ";
    std::getline(std::cin, temp);
 
    for (auto d : temp) {
       word.insert(d);
    }
    
    for (auto t : word) {
        int c = 0;
        
        c = word.count(t);
        leng.insert({ t ,c });
        
    }
    std::vector<std::pair<char, int>> elems(leng.begin(), leng.end());
    std::sort(elems.begin(), elems.end(), [](auto &a, auto &b) {return a.second > b.second; });

    std::cout << "[OUT]: \n";
   for (auto el : elems)
        print_pair(el);
    
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
