#pragma once
#include "Validator.h"

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

template <class T>
bool RangeValidator<T>::validate(T value)
{
	if (value <= m_minValue || value >= m_maxValue)
		return false;
	return true;
}

template <class T>
std::string RangeValidator<T>::getErrorMsg() const
{
	return "Out Of Range!\n";
}