#include "Form.h"

void Form::fillForm()
{
	m_answers.resize(m_questions.size());
	for (int question = 0; question < m_questions.size(); question++)
	{
		std::cout << m_questions[question] << std::endl;
		auto temp = std::cin ;
		std::cin >> m_answers[question];
	}
}

void Form::addField(std::string question)
{
	m_questions.push_back(question);
}