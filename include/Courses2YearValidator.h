#pragma once
#include "TwoBaseValidator.h"

template <class T1, class T2>
class Courses2YearValidator : public TwoBaseValidator
{
public:
	Courses2YearValidator(T1* facultyField, T2* m_facultyField);
	Courses2YearValidator& get() { return *this; };

private:
	T1* m_courseField;
	T2* m_yearField;

};

template <class T1, class T2>
Courses2YearValidator<T1, T2>::Courses2YearValidator(T1* courseField, T2* yearField)
{
	m_courseField = courseField;
	m_yearField = yearField;
}