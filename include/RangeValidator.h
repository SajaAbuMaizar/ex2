#pragma once
#include "Validator.h"

template <class T>
class RangeValidator : public Validator <T>
{
public:
	RangeValidator<T>(const T& min, const T& max);
	RangeValidator& get();

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