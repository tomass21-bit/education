#include "Exception.h"
#include <string>
#include <iostream>
#include "Figura.h"

 Bad_figure::Bad_figure(const std::string& _Message) : std::domain_error(_Message.c_str()){ }
 Bad_figure::Bad_figure(const std::string& _Message, std::string name, int a,int b,int c,int A,int B,int C) : std::domain_error(_Message.c_str()) {
	 std::cout <<name << " (" << "�������" << " " << " " << "a=" << a << " " << "b=" << b << " " << "c=" << c << "; ";
	 std::cout << "����" << " " << " " << "A=" << A << " " << "B=" << B << " " << "C=" << C << ") "<<"�� ������ , ������� ";
	 
 }
 Bad_figure::Bad_figure(const std::string& _Message, std::string name, int a, int b, int c, int d, int A, int B, int C, int D) : std::domain_error(_Message.c_str()) {
	 std::cout << name << " (" << "�������" << " " << " " << "a=" << a << " " << "b=" << b << " " << "c=" << c << " " << "d=" << d <<"; ";
	 std::cout << "����" << " " << " " << "A=" << A << " " << "B=" << B << " " << "C=" << C << " " << "D=" << D << ") " << "�� ������ , �������: ";

 }