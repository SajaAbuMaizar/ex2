#include "Form.h"

void Form::fillForm()
{
	for (int question = 0; question < m_fields.size(); question++)
	{
		if (!m_fields[question]->getValid())
		{
			std::cout << m_fields[question]->getQuestion() << std::endl;
			m_answers[question]->fillData();
		}
	}
}

void Form::addField(BaseField* field)
{
	m_fields.push_back(field);
}

void Form::addValidator(TwoBaseValidator* validator)
{
	m_validators.push_back(validator);
}

/*
std::ostream& operator<<(std::ostream& ostr, const Form& form)
{
	form.printFields(ostr);
	return ostr;
}

void Form::printFields(std::ostream& os) const
{
	for (size_t i = 0; i < m_questions.size(); i++)
		m_Fields[i]->print(os);

	for (size_t i = 0; i < m_FormValidators.size(); i++)
		if (!m_FormValidators[i]->getFormValidState())
			m_FormValidators[i]->fixFormFields();
}
*/