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


template <class T>
MinValidator<T>::MinValidator(const T& min)
{
	m_minValue = min;
}

template <class T>
bool MinValidator<T>::validate(T num)
{
	if (num < m_minValue)
		return false;
	return true;
}

template <class T>
std::string MinValidator<T>::getErrorMsg() const
{
	return "Out Of Range!\n";
}