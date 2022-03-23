#pragma once
#include "Validator.h"
#include <string>
#include <cctype>

class NoDigitValidator : public Validator <std::string>
{
public:
	NoDigitValidator();
	NoDigitValidator& get() { return *this; };
	bool validate(std::string my_string);
	std::string getErrorMsg() const;


private:

};

//the class c-tor
inline NoDigitValidator::NoDigitValidator()
{

}

//this function validates if the answer doesn't have numbers
//returns true if there's not a number in the string, false otherwise
inline bool NoDigitValidator::validate(std::string my_string)
{
	for (int i = 0; i < my_string.size(); i++)
		if (isdigit(my_string[i]))
			return false;
	return true;
}

//this function returns an error message
inline std::string NoDigitValidator::getErrorMsg() const
{
	return "Can't contain digits!\n";
}