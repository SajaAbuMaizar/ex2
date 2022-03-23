#pragma once
#include "Validator.h"

#include <iostream>

template <class T>
class RangeValidator : public Validator <T>
{
public:
	RangeValidator<T>(const T& min, const T& max);
	RangeValidator& get();
	bool validate(T value);
	virtual std::string getErrorMsg() const;

private:
	T m_minValue;
	T m_maxValue;

};

//the class c-tor
template <class T>
RangeValidator<T>::RangeValidator(const T& min, const T& max)
{
	m_minValue = min;
	m_maxValue = max;
}

template <class T>
RangeValidator<T>& RangeValidator<T>::get()
{
	return *this;
}

//this function validates if the number giver is in range
//returns true if in range, false otherwise
template <class T>
bool RangeValidator<T>::validate(T value)
{
	if (value < m_minValue || value > m_maxValue)
		return false;
	return true;
}

//this function returns an error message
template <class T>
std::string RangeValidator<T>::getErrorMsg() const
{
	return "Out Of Range!\n";
}