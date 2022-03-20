#pragma once
#include <string>

class BaseField
{
public:
	//virtual BaseField& get() = 0;
	virtual std::string getQuestion() const = 0;
	virtual bool getValid() const = 0;

private:

};