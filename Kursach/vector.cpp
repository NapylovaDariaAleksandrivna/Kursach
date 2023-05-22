#include "vector.h"
#include <iostream>


template<typename T, int max_size>
MyVector<T, max_size>::MyVector() : cur(0) {
	arr = new T[max_size];
}

template<typename T, int max_size>
MyVector<T, max_size>::~MyVector() { delete[] arr; }

template<typename T, int max_size>
T& MyVector<T, max_size>::operator[](int index)
{
	if (index < 0 || index >= cur)
		throw std::out_of_range("index out of range");
	return arr[index];
}

template<typename T, int max_size>
T MyVector<T, max_size>::operator[](int index)const
{
	if (index < 0 || index >= cur)
		throw std::out_of_range("index out of range");
	return arr[index];
}

template<typename T, int max_size>
void MyVector<T, max_size>::AddElemToMyVector(T val)
{
	if (cur >= max_size)
		throw std::overflow_error("vector is full");
	this->arr[cur++] = val;
}

template<typename T, int max_size>
void MyVector<T, max_size>::pop_back()
{
	if (cur <= 0)
		throw std::underflow_error("vector is empty");
	--cur;
}

template<typename T, int max_size>
void MyVector<T, max_size>::PrintMyVector() const
{
	for (int i = 0; i < cur; ++i)
		std::cout << arr[i] << '\t';
	std::cout << std::endl;
}

template<typename T, int max_size>
MyVector<T, max_size>& MyVector<T, max_size>::operator+=(double a)
{
	for (int i = 0; i < cur; ++i)
	{
		arr[i] += a;
	}
	return *this;
}
