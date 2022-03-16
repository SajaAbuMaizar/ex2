#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Data.h"

class Form
{
public:
	void fillForm();
	void addField(std::string question);

private:
	std::vector<std::string> m_questions;
	std::vector<DataBase*> m_answers;
};
