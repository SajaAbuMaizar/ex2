#pragma once
#include <string>

class TwoBaseValidator
{
public:
	TwoBaseValidator& get() { return *this; };
	virtual bool validate() = 0;
	virtual std::string getErrorMsg() const = 0;
	bool getValid() const { return m_valid; };

protected:
	bool m_valid;

private:

};