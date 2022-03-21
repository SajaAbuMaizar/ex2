#pragma once
#include <string>

template <class T>
class Validator 
{
public:
	virtual bool validate(T answer) = 0;
	virtual std::string getErrorMsg() const = 0;

protected:
	

private:

};