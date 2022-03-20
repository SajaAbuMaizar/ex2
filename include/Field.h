#pragma once
#include "BaseField.h"
#include "Validator.h"
#include <string>

template <class T>
class Field : public BaseField
{
public:
	Field(std::string my_string);
	std::string getQuestion() const;
	void addValidator(Validator<T>* validator);
	Field<T>& get();

private:
	std::string m_string;
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