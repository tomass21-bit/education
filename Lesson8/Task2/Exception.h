#pragma once
#include <iostream>

#include <string>
class Bad_figure : public std::domain_error {
public:
	
	explicit Bad_figure(const std::string& _Message);
	
};