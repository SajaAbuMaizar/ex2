#pragma once
#include <iostream>
#include "Validator.h"

class FacultyValue
{
public:
	FacultyValue(int faculty = 1);
	~FacultyValue();
	void setFaculty(int n);
	int getFaculty() const;

private:
	int m_FacultyType = 0;
};

std::istream& operator >>(std::istream& inp, FacultyValue& fValue);
std::ostream& operator <<(std::ostream& out, const FacultyValue& fValue);
bool operator>= (const FacultyValue& f1, const FacultyValue& f2);
bool operator<=(const FacultyValue& f1, const FacultyValue& f2);