// Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <clocale>

class Figura {
public:
    
    
    

    void print( ) {
        std::cout << name << ":\n";
        print_sides();
        print_angles();
    }
    

protected:
    std::string stor = "Стороны";
    std::string angle = "Углы";
    std::string name;
    Figura(std::string name) {
        this->name=name;
    }
   
   
     
     std::string get_name() {
         return name;
     }
     virtual void print_sides() {}
     virtual void print_angles() {}
     
};



class Triple : public Figura {
public:
    Triple() : Figura("Треугольник") { a = 30, b = 35, c = 50, A = 30, B = 60, C = 70; }
    Triple(int a, int b, int c, int A, int B, int C ) : Figura("Треугольник") {
        this->a = a, this->b = b, this->c = c, this->A = A, this->B = B, this->C = C;
    }
   
protected:
    Triple(int a, int b, int c, int A, int B, int C, std::string name) : Figura(name) {
        this->a = a, this->b = b, this->c = c, this->A = A, this->B = B, this->C = C;
    }
    void print_sides() override {
        std::cout << stor << ":" << " " << "a=" << a << "\t" << "b=" << b << "\t" << "c=" << c << std::endl;

    }
    void print_angles() override {
        std::cout << angle << ":" << "\t" << "A=" << A << "\t" << "B=" << B << "\t" << "C=" << C << std::endl << std::endl;
    }
private:
    int a;
    int b;
    int c;
    int A;
    int B;
    int C;
    
};

class Triple_pramoug : public Triple
{
public:
    
    
    Triple_pramoug(int a, int b, int c, int A, int B) : Triple(a, b, c, A, B, 90 , "Прямоугольный треугольник") {  }
    Triple_pramoug() : Triple(30, 35, 50, 30, 60, 90, "Прямоугольный треугольник") {  }
};

class Triple_ravnobed : public Triple
{
public:
    Triple_ravnobed(int a, int b,  int A, int B) : Triple(a, b, a, A, B, A, "Равнобедренный треугольник") {  }
    Triple_ravnobed() : Triple(20, 40, 20, 50, 70, 30, "Равнобедренный треугольник") {  }
    
};
class Triple_ravnostor : public Triple
{
public:
    Triple_ravnostor(int a) : Triple(a, a, a, 60, 60, 60, "Равноcторонний треугольник") {  }
    Triple_ravnostor() : Triple(20, 20, 20, 60, 60, 60, "Равноcторонний треугольник") { }
};

class Four : public Figura {
public:
    
    Four() : Figura("Четырехугольник") { a = 30, b = 35, c = 50, d=30,  A = 30, B = 60, C = 70, D=90 ; }
    Four(int a, int b, int c, int d, int A, int B, int C, int D) : Figura("Четырехугольник") {
        this->a = a, this->b = b, this->c = c, this->d = d, this->A = A, this->B = B, this->C = C, this->D = D;
    }
    void print_sides() override {
        
            std::cout << stor << ":" << " " << "a=" << a << "\t" << "b=" << b << "\t" << "c=" << c << "\t" << "d=" << d << std::endl;
        }
                   
            
     void print_angles() override {
            std::cout << angle << ":"<<"\t" << "A=" << A << "\t" << "B=" << B << "\t" << "C=" << C << "\t" << "D=" << D << std::endl << std::endl;

    }
    
    
  protected:
      
      Four(int a, int b, int A, int B,  std::string name) : Figura(name) {
          this->a = a, this->b = b, this->c = a, this->d = b, this->A = A, this->B = B, this->C = A, this->D = B;
      }
private:
    int a;
    int b;
    int c;
    int d;
    int A;
    int B;
    int C;
    int D;
};


class Paralelogram : public Four
{
public:
   
    Paralelogram() :Four (20, 25, 120, 60, "Паралелограм") { }
    Paralelogram(int a, int b,  int A, int B) : Four(a, b, A, B, "Паралелограм") {  }
protected:
    Paralelogram(int a, int b, int A, int B, std::string name) : Four(a, b,  A, B,  name) {  }
};
class Romb : public Paralelogram
{
public:
    Romb(int a,  int A, int B) : Paralelogram(a, a, A, B, "Ромб") {  }
    Romb() :Paralelogram (25, 25, 130, 70, "Ромб") {  }
};
class Pramoug : public Paralelogram
{
public:
    
    Pramoug() :Paralelogram(20, 40, 90, 90, "Прямоугольник") { }
    Pramoug(int a, int b ) : Paralelogram(a, b, 90, 90, "Прямоугольник") {  }
protected:
    Pramoug(int a, std::string name) : Paralelogram(a, a, 90, 90, name) {  }
};
class Quad : public Pramoug
{
public:
    
    Quad() : Pramoug(20,  "Квадрат") { }
    Quad(int a) : Pramoug(a, "Квадрат") { }
};


int main()
{
    setlocale(LC_ALL, "Russian");
    
    /*Triple t ;
    t.print();
    
    
    Triple_pramoug pr;
    pr.print();
   
    Triple_ravnobed rb;
    rb.print();
   
    Triple_ravnostor rs;
    rs.print();
    Four f ;
    f.print();

    Pramoug pra ;
    pra.print();
    
    Quad q ;
    q.print();
    
    Paralelogram par ;
    par.print();

    Romb r;
    r.print();*/

    
    Figura* p_fig = nullptr;
   

    Triple t(15, 20, 30, 50, 60, 70);
    p_fig = &t;
    p_fig->print();

    Triple_pramoug pr(20, 15, 30, 50, 60);
    p_fig = &pr;
    p_fig->print();

    Triple_ravnobed rb(20, 30, 50, 40);
    p_fig = &rb;
    p_fig->print();

    Triple_ravnostor rs (10 );
    p_fig = &rs;
    p_fig->print();

   

    Four f (10, 20, 30, 40, 50, 60, 70, 80);
    p_fig = &f;
    p_fig->print();

    Pramoug pra(10, 20);
    p_fig = &pra;
    p_fig->print();

    Quad q(40);
    p_fig = &q;
    p_fig->print();

    Paralelogram par(20, 30, 30, 40);
    p_fig = &par;
    p_fig->print();

    Romb r(30, 30, 150);
    p_fig = &r;
    p_fig->print();
   


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
