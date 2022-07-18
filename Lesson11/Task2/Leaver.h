#pragma once
#ifdef task2_exports
#define STR_BYE __declspec(dllexport)
#else
#define STR_BYE __declspec(dllimport)
#endif
#include <string>

class Leaver {
public:
	STR_BYE std::string leave(const std::string& len);

};