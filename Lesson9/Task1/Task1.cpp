// Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include<numeric>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		sokrat(numerator, denominator);
		numerator_ = numerator;
		denominator_ = denominator;
	}

	bool operator==(const Fraction& s)
	{
		
		if (this->numerator_ == this->denominator_ && s.numerator_ == s.denominator_) {
			return true;
		}
		else
			return false;
	}

	bool operator!=(const Fraction& s)
	{	
		
	return !(*this==s);
	}

	bool operator<(const Fraction& s)
	{
		int numerator1 = this->numerator_;
		int numerator2 = s.numerator_;
				
		 numerator1 *= s.denominator_;
		 numerator2 *=  this->denominator_;
		
		 if (*this != s) {
			 return	 abs(numerator1) < abs(numerator2);
		 }
		 else
			 return false;
	}

	bool operator>(const Fraction& s)
	{
		return !(*this < s) ;
	}

	bool operator<=(const Fraction& s)
	{
		return (*this == s) || (*this < s);
	}

	bool operator>=(const Fraction& s)
	{
		return !(*this == s) || !(*this < s);
	}


	void sokrat(int& a, int& b) {
		int x = std::gcd(a, b);
		a /= x;
		b /= x;

	}
	
};

int main()
{
	Fraction f1(4, 3);
	Fraction f2(6, -11);
	
	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
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
