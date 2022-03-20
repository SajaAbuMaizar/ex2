#include "Form.h"

void Form::fillForm()
{
	m_answers.resize(m_questions.size());
	for (int question = 0; question < m_questions.size(); question++)
	{
		std::cout << m_questions[question] << std::endl;
		m_answers[question]->fillData();
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