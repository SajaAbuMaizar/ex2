#pragma once
#include <iostream>
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
	T getAnswer() const;
	void addValidator(Validator<T>* validator);
	Field<T>& get();
	virtual bool getValid() const;
	void fillData();
	void showData();
	void print(std::ostream& os);
	bool validate();
	void setValid();
	//~Field();

private:
	std::string m_string;
	std::string m_errorMessage;
	bool m_valid;
	Validator<T>* m_validator;
	T m_answer;
	
};

//this function prints out the field with its answer
//in case of an error in the answer it prints an error message
template <class T>
void Field<T>::print(std::ostream& os)
{
	os << m_string << " = " << m_answer;
	if (!m_valid)
		os << "           " << m_errorMessage;
	os << std::endl;
}

//this function takes in the user's input
template <class T>
void Field<T>::fillData() {
	std::cin >> m_answer;
}

template <class T>
void Field<T>::showData() {
	std::cout << m_answer;
}

//the class c-tor
template <class T>
Field<T>::Field(std::string my_string)
{
	m_string = my_string;
	m_valid = false;
}

template <class T>
std::string Field<T>::getQuestion() const
{
	return m_string;
}

template <class T>
T Field<T>::getAnswer() const
{
	return m_answer;;
}

//this function adds an appropriate validator to every field
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

//this function sets the validation of the field called to false
template<class T>
void Field<T>::setValid()
{
	m_valid = false;
}

//this function validates the function according to the validator
//returns true if the field is correct, false otherwise.
template<class T>
bool Field<T>::validate()
{
	m_valid = m_validator->validate(m_answer);
	m_errorMessage = m_validator->getErrorMsg();//setting an error msg in case of an error
	return m_valid;
}

/*
//the class d-tor
template<class T>
Field<T>::~Field()
{
	delete m_validator;
}*/