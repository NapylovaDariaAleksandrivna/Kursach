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
	double eval(std::string pref, double x);
	void toGive(std::string pref, double x1 = -10, double x2 = 10, double dep = 0.02);
	double operation(char op, double a, double b);
	double DegToRad(double D);
	int GetSize()const { return arrX.GetSize(); }

	parser* ukp;//????????

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

