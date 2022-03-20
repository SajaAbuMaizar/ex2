#pragma once
#include "BaseField.h"
#include "Validator.h"
#include <string>

template <class T>
class Field : public BaseField
{
public:
	Field(std::string my_string);
	virtual ~Field() = default;
	std::string getQuestion() const;
	void addValidator(Validator<T>* validator);
	Field<T>& get();
	virtual bool getValid() const;

private:
	std::string m_string;
	bool m_valid;
	Validator<T>* m_validator;
};

template <class T>
Field<T>::Field(std::string my_string)
{
	m_string = my_string;
}

template <class T>
std::string Field<T>::getQuestion() const
{
	return m_string;
}

template <class T>
void Field<T>::addValidator(Validator<T>* validator)
{
	m_validator = validator;
}

template <class T>
Field<T>& Field<T>::get()
{
	return *this;
}

template<class T>
bool Field<T>::getValid() const
{
	return m_valid;
}

