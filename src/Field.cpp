#include "Field.h"

template <class T>
Field<T>::Field<T>(std::string my_string)
{
	m_string = string;
}

template <class T>
std::string Field<T>::get()
{
	return m_string;
}