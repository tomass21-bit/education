// task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>


class Big_int {
public:
	Big_int(const std::string& i) {
		std::vector<unsigned> b_int;
		set(i);
	}

	~Big_int() { b_int.clear(); }

	Big_int(const Big_int& obj) {
		for (auto t : obj.b_int)
			b_int.push_back(t);

	}

	Big_int(Big_int&& obj)noexcept : b_int(std::move(obj.b_int)) {}

	Big_int& operator = (Big_int&& obj)noexcept {
		b_int = std::move(obj.b_int);
		return *this;
	}
	Big_int& operator = (const Big_int& obj) {
		for (auto t : obj.b_int)
			b_int.push_back(t);
		return *this;
	}

	

	Big_int& operator + (Big_int& obj) {
		int temp = 0;
		if (b_int.size() == obj.b_int.size()) {
			for (int i = 0; i < b_int.size(); i++) {
				temp = b_int[i] + obj.b_int[i];
				if (temp > 9) {
					b_int[i] = temp % 10;
					if (i == b_int.size() - 1) {
						b_int.push_back(1);
					}
					else
						b_int[i + 1]++;
					
				}
				else
					b_int[i] = temp;

			}

		}
		else if (b_int.size() > obj.b_int.size()) {
			for (int i = 0; i < obj.b_int.size(); i++) {

				temp = b_int[i] + obj.b_int[i];
				if (temp > 9) {
					b_int[i] = temp % 10;
					b_int[i + 1]++;
				}
				else
					b_int[i] = temp;
			}

		}
		else {
			for (int i = 0; i < b_int.size(); i++) {
				temp = b_int[i] + obj.b_int[i];
				if (temp > 9) {
					obj.b_int[i] = temp % 10;
					obj.b_int[i + 1]++;
				}
				else
					obj.b_int[i] = temp;
			}
			b_int = move(obj.b_int);
		}
		return *this;
	}
	Big_int& operator * (const int& num) {
		unsigned temp = 0;
		
		std::vector<unsigned> t_int(b_int.size(),0);
		for (auto i = 0; i < b_int.size(); i++) {
		
			temp = b_int[i] * num;
			if (i == b_int.size() - 1) {
				if (temp > 9) {
					t_int.push_back(temp / 10);
					t_int[i] += temp % 10;
					if (t_int[i] > 9) {
						t_int[i + 1] += t_int[i] / 10;
						t_int[i] = t_int[i] % 10;
					}
				}
				else {
					t_int[i] += temp;
					if (t_int[i] > 9) {
						t_int[i + 1] += t_int[i] / 10;
						t_int[i] = t_int[i] % 10;
					}
				}
			}
			else {
				if (temp > 9) {
					t_int[i + 1] += temp / 10;
					t_int[i] += temp % 10;
					if (t_int[i] > 9) {
						t_int[i + 1] += t_int[i] / 10;
						t_int[i] = t_int[i] % 10;
					}
				}
				else {
					t_int[i] += temp;
					if (t_int[i] > 9) {
						t_int[i + 1] += t_int[i] / 10;
						t_int[i] = t_int[i] % 10;
					}
				}
			}
				

					
				
			
		}
		b_int = move(t_int);
		return *this;
	}
	friend std::ostream& operator << (std::ostream& strm, const Big_int& obj) {
		for (auto it = obj.b_int.rbegin(); it != obj.b_int.rend(); it++) {
			strm << *it << " ";
		}
	return strm;
	}



protected:
	std::vector<unsigned> b_int;
	unsigned perenos=0;
	void set(const std::string& num) {
		for (auto it = num.rbegin(); it != num.rend(); it++) {
			b_int.push_back(*it - '0');
		}
	}

};




int main()
{
	auto number1 = Big_int("11457543537625463815516739346516553786936987");
	auto number2 = Big_int("7852411617436436467067419517165612348568158");
	auto number3 = Big_int("81819");
	std::cout << number1 << std::endl;
	std::cout << number2 << std::endl;
	auto result = number1 + number2;

	std::cout << result << std::endl;
	auto result1 = number3 * 9*2;
	std::cout << result1 << std::endl;
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
