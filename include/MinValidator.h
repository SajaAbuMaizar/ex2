#pragma once
#include "Validator.h"

template <class T>
class MinValidator : public Validator <short>
{
public:
	MinValidator<T>(const T& min);
	MinValidator& get() { return *this; };

private:
	T m_minValue;

};

template <class T>
MinValidator<T>::MinValidator(const T& min)
{
	m_minValue = min;
}