#include "FacultyValue.h"

FacultyValue::FacultyValue(int faculty)
	:m_FacultyType(faculty)
{
}


FacultyValue::~FacultyValue()
{
}


void FacultyValue::setFaculty(int n)
{
	m_FacultyType = n;
}

int FacultyValue::getFaculty() const
{
	return m_FacultyType;
}

std::istream& operator>>(std::istream& inp, FacultyValue& fValue)
{
	int n;
	inp >> n;
	fValue.setFaculty(n);
	return inp;
}

//this function (operator<<) takes in the faculty number and converts it into 
//its name (1 = computer science, 2 = Medicine, 3 = Literature)
std::ostream& operator<<(std::ostream& out, const FacultyValue& fValue)
{
	switch (fValue.getFaculty())
	{
	case 1:
		out << "Computer Science";
		break;
	case 2:
		out << "Medicine";
		break;
	case 3:
		out << "Literature";
		break;
	default:
		out << fValue.getFaculty();
		break;
	}
	return out;
}

bool operator>(const FacultyValue& f1, const FacultyValue& f2)
{
	return f1.getFaculty() > f2.getFaculty();
}

bool operator<(const FacultyValue& f1, const FacultyValue& f2)
{
	return f1.getFaculty() < f2.getFaculty();
}
