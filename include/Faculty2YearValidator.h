#pragma once
#include "TwoBaseValidator.h"
#include "Field.h"
#include "FacultyValue.h"

enum FacultyType { ComputerScience = 1, Medicine, Literature};

template <class T1, class T2>
class Faculty2YearValidator : public TwoBaseValidator
{
public:
	Faculty2YearValidator(T1* facultyField, T2* m_facultyField);
	Faculty2YearValidator& get() { return *this; };
	bool validate();
	std::string getErrorMsg() const;
	void setFieldsValid();

private:
	T1* m_facultyField;
	T2* m_yearField;

};

template <class T1, class T2>
void Faculty2YearValidator<T1, T2>::setFieldsValid()
{
	m_facultyField->setValid();
	m_yearField->setValid();
}

template <class T1, class T2>
Faculty2YearValidator<T1,T2>::Faculty2YearValidator(T1* facultyField, T2* yearField)
{
	m_facultyField = facultyField;
	m_yearField = yearField;
}

template <class T1, class T2>
bool Faculty2YearValidator<T1, T2>::validate()
{
	int faculty = m_facultyField->getAnswer().getFaculty();
	int year = m_yearField->getAnswer();

	m_valid = true;
	switch (faculty)
	{
	case(ComputerScience):
		if (year > 4)
			m_valid = false;
		break;

	case(Literature):
		if (year > 3)
			m_valid = false;
		break;

	case(Medicine):
		if (year > 7)
			m_valid = false;
		break;
	default:
		m_valid = false;
	}
	if (!m_valid)
		setFieldsValid();
	return m_valid;
}

template<class T1, class T2>
std::string Faculty2YearValidator<T1, T2>::getErrorMsg() const
{
	return "Faculty and year don't match!\n";
}