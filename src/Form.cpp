#include "Form.h"

//this function fills in the form that we get, it prints the question
//and waits until getting the answer
void Form::fillForm()
{
	for (int question = 0; question < m_fields.size(); question++)
	{
		if (!m_fields[question]->getValid())
		{
			std::cout << m_fields[question]->getQuestion() << std::endl;
			m_fields[question]->fillData();
		}
	}
}

//this function adds a field to the form (a question with its answer)
void Form::addField(BaseField* field)
{
	m_fields.push_back(field);
}

//this function adds a specific type of validator that validates that
//the answer for the question is correct
void Form::addValidator(TwoBaseValidator* validator)
{
	m_validators.push_back(validator);
}

//this function validates all the fields in the form
//returns true if the form doesn't have any errors, false otherwise 
bool Form::validateForm()
{
	m_valid = true;
	for (int answer = 0; answer < m_fields.size(); answer++)//check every field
		if (!m_fields[answer]->validate())
			m_valid = false;

	if (m_valid) //check the form correcteness only if every field is correct on itself
		for (int answer = 0; answer < m_validators.size(); answer++)
			if (!m_validators[answer]->validate())
				m_valid = false;

	return m_valid;
}

std::ostream& operator<<(std::ostream& ostr, const Form& form)
{
	form.printFields(ostr);
	return ostr;
}

//this function prints every field with its answer that the user entered
void Form::printFields(std::ostream& os) const
{
	for (size_t i = 0; i < m_fields.size(); i++)
		m_fields[i]->print(os);

	for (size_t i = 0; i < m_validators.size(); i++)
		if (!m_validators[i]->getValid())//if something's wrong in a field,print error msg
			os << m_validators[i]->getErrorMsg();
}
