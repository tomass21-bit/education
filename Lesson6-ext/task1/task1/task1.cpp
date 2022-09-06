

#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

template <class T>
T pow(T a) {
    
        return a * a;
}
template<>
std::vector<int> pow(std::vector<int> a) {
    for (auto& b : a)
            b *= b;
    return a;

}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<int> a ;
    int temp=0;
    int cases = 0;
    int t=0;
    
    std::cout << "Введите 1 если нужно работать целым числом. Введите 2 если нужно работать с вектором чисел: \n";
    std::cin >> cases;
    if (cases == 1) {
        std::cout << "IN: ";
        std::cin >> t;
        std::cout << "OUT: " << pow(t);
    }
        
    
    else if (cases == 2) {
        std::cout << "после ввода строки чисел введите q \n";
        std::cout << "IN: ";
        while (std::cin >> temp)
        {
            a.push_back(temp);
        }
        std::cout << "OUT: ";
        a = pow(a);
        for (auto c : a)
            std::cout << c << " ";

    }
     
    return 0;
       

}

