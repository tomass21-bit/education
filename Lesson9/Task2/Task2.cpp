// Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <clocale>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	
	void operator+(const Fraction& s)
	{
		int numerator = 0;
		int denominator = 0;
		if (this->denominator_ == s.denominator_)
		{
			 numerator = this->numerator_ + s.numerator_;
			 denominator = s.denominator_;
		}
		else
		{
			 numerator = (this->numerator_ * s.denominator_) + (s.numerator_ * this->denominator_);
			 denominator = s.denominator_*this->denominator_;
			 
		}
		sokrat(numerator, denominator);
		std::cout << this->numerator_<<"/"<< this->denominator_ <<" + " << s.numerator_ << "/" << s.denominator_<<"= " << numerator << "/" << denominator << '\n';
		
	}

	void operator-(const Fraction& s)
	{
		int numerator = 0;
		int denominator = 0;
		if (this->denominator_ == s.denominator_)
		{
			numerator = this->numerator_ - s.numerator_;
			denominator = s.denominator_;
		}
		else
		{
			numerator = (this->numerator_ * s.denominator_) - (s.numerator_ * this->denominator_);
			denominator = s.denominator_ * this->denominator_;

		}
		sokrat(numerator, denominator);
		std::cout << this->numerator_ << "/" << this->denominator_ << " - " << s.numerator_ << "/" << s.denominator_ << "= " << numerator << "/" << denominator << '\n';

	}
	void operator*(const Fraction& s)
	{
		int numerator = 0;
		int denominator = 0;
		
			numerator = this->numerator_ * s.numerator_ ;
			denominator = s.denominator_ * this->denominator_;

			sokrat(numerator, denominator);

		
		std::cout << this->numerator_ << "/" << this->denominator_ << " * " << s.numerator_ << "/" << s.denominator_ << "= " << numerator << "/" << denominator << '\n';

	}
	void operator/(const Fraction& s)
	{
		int numerator = 0;
		int denominator = 0;

		numerator = this->numerator_ * s.denominator_ ;
		denominator = s.numerator_ * this->denominator_;

		sokrat(numerator, denominator);


		std::cout << this->numerator_ << "/" << this->denominator_ << " / " << s.numerator_ << "/" << s.denominator_ << "= " << numerator << "/" << denominator << '\n';

	}
	Fraction& operator++()
	{
		numerator_ = numerator_ + denominator_;
		 
		

		return *this;


		

	}
	Fraction operator++(int)
	{
		Fraction temp = *this;

		
		++*this;
		

		return temp;

	}
	Fraction& operator--()
	{


		
		numerator_ = numerator_ - denominator_;
		

		return *this;




	}
	Fraction operator--(int)
	{
		Fraction temp = *this;

		--*this ;



		return temp;

	}
	Fraction& operator-()
	{
		numerator_*=-1 ;
		return *this;

	}


protected:
	int gcd(int a, int b) {
		a = abs(a), b = abs(b);
		if (b == 0)return a;
		else return gcd(b, a % b);
	}
	void sokrat(int& a, int& b) {
		int x = gcd(a, b);
		a /= x;
		b /= x;
		
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int numerator=0;
	int denominator = 0;

	std::cout << "Введите числитель дроби 1: ";
	std::cin >> numerator;
	std::cout << std::endl;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> denominator;
	std::cout << std::endl;
	Fraction f1(numerator, denominator);
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> numerator;
	std::cout << std::endl;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> denominator;
	std::cout << std::endl;
	Fraction f2(numerator, denominator);
	
	f1 + f2;
	f1 - f2;
	f1 * f2;
	f1 / f2;
	++f1* f2;
	f1--* -f2;

	f1 / f1;
	-f1 * f2;
	
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
