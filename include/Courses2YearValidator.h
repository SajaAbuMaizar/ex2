#pragma once
#include "TwoBaseValidator.h"

template <class T1, class T2>
class Courses2YearValidator : public TwoBaseValidator
{
public:
	Courses2YearValidator(T1* facultyField, T2* m_facultyField);
	Courses2YearValidator& get() { return *this; };
	virtual bool validate();
	std::string getErrorMsg() const;
	void setFieldsValid();

private:
	T1* m_courseField;
	T2* m_yearField;

};

template <class T1, class T2>
void Courses2YearValidator<T1, T2>::setFieldsValid()
{
	m_courseField->setValid();
	m_yearField->setValid();
}

template <class T1, class T2>
Courses2YearValidator<T1, T2>::Courses2YearValidator(T1* courseField, T2* yearField)
{
	m_courseField = courseField;
	m_yearField = yearField;
}

template<class T1, class T2>
bool Courses2YearValidator<T1, T2>::validate()
{
	m_valid = false;
	short course = m_courseField->getAnswer();
	int year = m_yearField->getAnswer();

	if (year < 1 || year > 7 || course < 2 || course > 10)
		m_valid = false;

	if ((year == 1 || year == 2) && (course >= 2 && course <= 6))
		m_valid = true;

	if ((year == 3 || year == 4) && (course == 2 && course <= 10))
		m_valid = true;

	if (year >= 5 && (course == 2 && course <= 8))
		m_valid = true;

	if (!m_valid)
		setFieldsValid();
	return m_valid;
}

template<class T1, class T2>
std::string Courses2YearValidator<T1, T2>::getErrorMsg() const
{
	return "Courses and year don't match!\n";
}