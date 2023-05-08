//#pragma once
//
//#include <iostream>
//
//class MyVector {
//	static int counter;
//public:
//	static double GetCounter();
//	MyVector();
//	MyVector(int max_size);
//	MyVector(double* arr, int size);
//	MyVector(const MyVector& right);
//	~MyVector();
//	double GetElemByIndex(int index)const;
//	double& GetElemByIndex(int index);
//	void PrintMyVector()const;
//	void AddElemToMyVector(double val);
//	void RemoveElemFromMyVector(double val);
//	void RemoveElemFromBack();
//	int GetSize()const { return cur; }
//	void Clean();
//	MyVector& operator= (const MyVector& right);
//	double& operator[](int index);
//	double operator[](int index)const;
//	MyVector operator+ (const MyVector& right)const;
//	MyVector& operator += (double a);
//	MyVector& operator++();
//	MyVector operator++(int);
//protected:
//	int GetCapacity()const { return max_size; }
//private:
//	double* arr;
//	int max_size;
//	int cur;
//};
//
//int operator+(int left, const MyVector& right);
//std::ostream& operator<<(std::ostream& out, const MyVector& obj);
//std::istream& operator>> (std::istream& in, MyVector& obj);
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