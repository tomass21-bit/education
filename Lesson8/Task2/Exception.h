#pragma once
#include <iostream>

#include <string>
class Bad_figure : public std::domain_error {
public:
	
	explicit Bad_figure(const std::string& _Message);
	Bad_figure(const std::string& _Message,std::string name, int a, int b, int c, int A, int B, int C);
	
	Bad_figure(const std::string& _Message, std::string name, int a, int b, int c,int d, int A, int B, int C, int D);
};