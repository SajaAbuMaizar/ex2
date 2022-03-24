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
	//~Faculty2YearValidator();

private:
	T1* m_facultyField;
	T2* m_yearField;

};

//this function sets the validation for the two fields in the class private members to false
template <class T1, class T2>
void Faculty2YearValidator<T1, T2>::setFieldsValid()
{
	m_facultyField->setValid();
	m_yearField->setValid();
}

//the class c-tor
template <class T1, class T2>
Faculty2YearValidator<T1,T2>::Faculty2YearValidator(T1* facultyField, T2* yearField)
{
	m_facultyField = facultyField;
	m_yearField = yearField;
}

//this function validate that the faculty and the year for the student are matchable
//returns true if fit, false otherwise.
template <class T1, class T2>
bool Faculty2YearValidator<T1, T2>::validate()
{
	int faculty = m_facultyField->getAnswer().getFaculty();
	int year = m_yearField->getAnswer();

	m_valid = true;
	switch (faculty)//compare accoring to the requierments
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

//this function returns a special error message for the case if
//the faculty and years don't match
template<class T1, class T2>
std::string Faculty2YearValidator<T1, T2>::getErrorMsg() const
{
	return "Faculty and year don't match!\n";
}

/*
//the class d-tor
template<class T1, class T2>
Faculty2YearValidator<T1,T2>::~Faculty2YearValidator()
{
	delete m_facultyField;
	delete m_yearField;
}
*/