#pragma once
#include <string>

class BaseField
{
public:
	virtual std::string getQuestion() const = 0;
	virtual bool getValid() const = 0;
	virtual void fillData() = 0;
	virtual void showData() = 0;
	virtual void print(std::ostream& os) = 0;
	virtual bool validate() = 0;
	virtual void setValid() = 0;

private:

};