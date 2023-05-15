
#pragma once

#include <iostream>
template<typename T, int max_size>
class MyVector
{
public:
	MyVector();
	~MyVector();
	void AddElemToMyVector(T);
	void pop_back();
	int GetSize()const { return cur; }

	void PrintMyVector()const;
	T& operator[](int index);
	T operator[](int index)const;
	MyVector& operator += (int);
private:
	T* arr;
	int cur;
};
template<typename T, int max_size>
std::ostream& operator<<(std::ostream& out, const MyVector<T, max_size>& obj)
{
	obj.PrintMyVector();
	return out;
}
template<typename T, int max_size>
std::istream& operator>>(std::istream& in, MyVector<T, max_size>& obj)
{
	int n = 0;
	in >> n;
	for (int i = 0; i < n; ++i)
	{
		int val;
		in >> val;
		obj.AddElemToMyVector(val);
	}
	return in;
}