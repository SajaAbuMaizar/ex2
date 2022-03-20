#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Data.h"
#include "BaseField.h"
#include "TwoBaseValidator.h"

class Form
{
public:
	void fillForm();
	void addField(BaseField* field);
	void addValidator(TwoBaseValidator* validator);

private:
	std::vector<BaseField*> m_fields;
	std::vector<TwoBaseValidator*> m_validators;
	std::vector<DataBase<class T>*> m_answers;

};
