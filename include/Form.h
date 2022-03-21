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
	Form() {m_valid = true; };
	void fillForm();
	void addField(BaseField* field);
	void addValidator(TwoBaseValidator* validator);
	bool validateForm();
	void printFields(std::ostream& os) const;

private:
	std::vector<BaseField*> m_fields;
	std::vector<TwoBaseValidator*> m_validators;
	bool m_valid;

};

std::ostream& operator<<(std::ostream& ostr, const Form& form);
