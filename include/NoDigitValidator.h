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

inline NoDigitValidator::NoDigitValidator()
{

}

inline bool NoDigitValidator::validate(std::string my_string)
{
	for (int i = 0; i < my_string.size(); i++)
		if (isdigit(my_string[i]))
			return false;
	return true;
}

inline std::string NoDigitValidator::getErrorMsg() const
{
	return "Can't contain digits!\n";
}