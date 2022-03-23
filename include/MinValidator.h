#pragma once
#include "Validator.h"

template <class T>
class MinValidator : public Validator <short>
{
public:
	MinValidator<T>(const T& min);
	MinValidator& get() { return *this; };
	bool validate(T num);
	std::string getErrorMsg() const;

private:
	T m_minValue;

};

//the class c-tor
template <class T>
MinValidator<T>::MinValidator(const T& min)
{
	m_minValue = min;
}

//this function validate if the number is less than the classe's private member (m_minValue)
//returns true if the id number is larger than the min value, false otherwise
template <class T>
bool MinValidator<T>::validate(T num)
{
	if (num < m_minValue)
		return false;
	return true;
}

//this function returns an error message
template <class T>
std::string MinValidator<T>::getErrorMsg() const
{
	return "Out Of Range!\n";
}