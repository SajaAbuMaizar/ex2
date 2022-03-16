#pragma once
#include <string>

template <class T>
class Field
{
public:
	Field(std::string my_string);
	std::string get();

private:
	std::string m_string;
};
