// task3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <thread>
#include <mutex>
#include <windows.h>
#include < string_view >
class Myt {
public:
	Myt(std::string len_in):len(len_in) {};
	~Myt() { len.clear(); }
	std::mutex m;
	std::string len;
};







void swap_lock(Myt& l,Myt&  r) noexcept {
	
	std::lock (l.m,r.m);
	
	
	swap(l.len,r.len);
	
	l.m.unlock();
	r.m.unlock();
	std::cout << "swap_lock" << std::endl;
}

void swap_scoped_lock(Myt& l, Myt& r) noexcept {
	std::scoped_lock lock1(l.m,r.m);
	
	swap(l.len,r.len);
	std::cout << "swap_scoped_lock" << std::endl;
}

void swap_unique_lock(Myt& l, Myt& r) noexcept {
	std::unique_lock lock1(l.m, std::defer_lock);
	std::unique_lock lock2(r.m, std::defer_lock);
	std::lock(lock1, lock2);
	swap(lock1, lock2);
	std::cout << "swap_unique_lock" << std::endl;
}




int main()
{
	setlocale(LC_ALL, "Rus");
	Myt left("left");
	Myt right("right");
	std::thread t1 (swap_lock, std::ref(left), std::ref (right));
	std::thread t2(swap_scoped_lock, std::ref(left), std::ref (right));
	std::thread t3(swap_unique_lock, std::ref(left), std::ref (right));
	t1.join();
	t2.join();
	t3.join();
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
