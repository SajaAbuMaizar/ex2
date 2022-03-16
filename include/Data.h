#pragma once
#include "DataBase.h"

template <class T>
class Data : public DataBase
{
public:
	Data(const& T value) { m_value = value; };

private:
	T m_value;
};