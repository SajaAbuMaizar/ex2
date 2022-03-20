#pragma once
#include <iostream>
#include "DataBase.h"
#include <vector>

template <class T>
class Data : public DataBase<T>
{
public:
	void fillData();
	void showData();

private:
	T m_value;
};

template <class T>
void Data<T>::fillData() {
	std::cin >> m_value;
}

template <class T>
void Data<T>::showData() {
	std::cout << m_value;
}