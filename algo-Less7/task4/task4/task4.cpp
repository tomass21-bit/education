#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>


void dsf(int** arr, int vertex, int* visited, int size,int comp) {

    visited[vertex] = comp;
    
    for (int i = 0; i < size; i++) {
        if (arr[vertex][i] == 1) {
            if (visited[i] == 0) {

                dsf(arr, i, visited, size,comp);
            }
        }

    }

}
void dsf(int** arr, int size) {
    int comp = 0;
    int* arr_visit = new int[size]();
    for (int i = 0; i < size; i++) {
        if (arr_visit[i] == 0) {
            comp++;
            dsf(arr, i, arr_visit, size, comp);
        }
    }
    std::cout << "Принадлежность вершин компонентам связности : \n";
    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << " - " << arr_visit[i] << std::endl;
    }
    std::cout << "Количество компонентов связности в графе: "<<comp;
    

    delete[] arr_visit;
}





int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size = 0;
    int num = 0;


    std::ifstream fin("graf.txt"); // пытаемся открыть файл
    if (fin.is_open()) {
        std::string s;
        fin >> s;
        size = stoi(s);
        int** arr = new int* [size];
        for (int i = 0; i < size; i++) {
            arr[i] = new int[size];
        }

        while (!fin.eof()) {

            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    fin >> s;
                    num = stoi(s);
                    arr[i][j] = num;
                }
            }

        }

        dsf(arr, size);

        
        
        for (int i = 0; i < size; i++) {
            delete[] arr[i];
        }
        delete[] arr;

    }



    else {
        std::cout << "Не получилось открыть файл!" << std::endl;

    }


}