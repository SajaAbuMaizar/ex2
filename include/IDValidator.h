#pragma once
#include <cstdint>
#include "Validator.h"

class IDValidator : public Validator <uint32_t>
{
public:
	IDValidator();
	IDValidator& get() { return *this; };
    virtual bool validate(uint32_t id);
	virtual std::string getErrorMsg() const;

private:
};

inline IDValidator::IDValidator()
{
}

//this function validates the number of the id accoring to the control digit
//returns true if the id number is correct, false otherwise
inline bool IDValidator::validate(uint32_t id)
{
	std::string temp = std::to_string(id);

	if (temp.size() != 9)
		return false;

	int counter = 0;
	int incnum;

	for (unsigned int i = 0; i < temp.size(); i++)
	{
		//multiply digit by 1 or 2
		incnum = ((int)temp[i] - 48) * ((i % 2) + 1);
		counter += (incnum > 9) ? incnum - 9 : incnum;
		//sum the digits up and add to counter
	}

	return (counter % 10 == 0);
}

//this function returns an error message to the wrong control digit
inline std::string IDValidator::getErrorMsg() const
{
	return "Wrong Control Digit!\n";
}