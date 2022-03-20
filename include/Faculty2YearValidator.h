#pragma once
#include "TwoBaseValidator.h"
#include "Field.h"

template <class T1, class T2>
class Faculty2YearValidator : public TwoBaseValidator
{
public:
	Faculty2YearValidator(T1* facultyField, T2* m_facultyField);
	Faculty2YearValidator& get() { return *this; };

private:
	T1* m_facultyField;
	T2* m_yearField;

};

template <class T1, class T2>
Faculty2YearValidator<T1,T2>::Faculty2YearValidator(T1* facultyField, T2* yearField)
{
	m_facultyField = facultyField;
	m_yearField = yearField;
}
