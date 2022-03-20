#pragma once
#include "Validator.h"
#include <string>

class NoDigitValidator : public Validator <std::string>
{
public:
	NoDigitValidator();
	NoDigitValidator& get() { return *this; };


private:

};

NoDigitValidator::NoDigitValidator()
{

}