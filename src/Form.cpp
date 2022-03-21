#include "Form.h"

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

void Form::addField(BaseField* field)
{
	m_fields.push_back(field);
}

void Form::addValidator(TwoBaseValidator* validator)
{
	m_validators.push_back(validator);
}

bool Form::validateForm()
{
	m_valid = true;
	for (int answer = 0; answer < m_fields.size(); answer++)
		if (!m_fields[answer]->validate())
			m_valid = false;

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

void Form::printFields(std::ostream& os) const
{
	for (size_t i = 0; i < m_fields.size(); i++)
		m_fields[i]->print(os);

	for (size_t i = 0; i < m_validators.size(); i++)
		if (!m_validators[i]->getValid())
			os << m_validators[i]->getErrorMsg();
}
