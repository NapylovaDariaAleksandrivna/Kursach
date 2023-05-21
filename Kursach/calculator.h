#pragma once
#include"tstack.h"
#include "parser.h"
#include"func.h"
#include <iostream>
#include<string>
#include"vector.cpp"
//****************

//****************
class calculator
{
public:
	double eval(std::string pref, double x)const;
	void toGive(std::string pref, int n = 0);
	double operation(char op, double a, double b)const;
	double DegToRad(double D)const;

	int GetSize()const { return this->arrX.GetSize(); }
	calculator(std::string str, int n)
	{
		toGive(ukp->toPstfx(str), n);
	};
	std::string getOut(std::string str) {
		return ukp->toPstfx(str);
	}
	calculator() {};
	parser* ukp;

	void getArr()const { 
		std::cout << "x: ";
		arrX.PrintMyVector();
		std::cout << "\ny: ";
		arrY.PrintMyVector();
		std::cout << "\n";
	}
	MyVector<double, 2000> arrX;
	MyVector<double, 2000> arrY;
private:
	
};
std::ostream& operator<< (std::ostream& out, const calculator& obj);

