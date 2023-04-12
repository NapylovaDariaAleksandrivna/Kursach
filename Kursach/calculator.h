#pragma once
#include"tstack.h"
#include "parser.h"
#include"function.h"
#include <iostream>
#include<string>	
#include"vector.h"
class calculator
{
public:
	double eval(std::string pref, double x);
	void toGive(std::string pref, MyVector &arrY, MyVector &arrX, double x1 = -5, double x2 = 5, double y1 = -5, double y2 = 5, double dep = 0.1);
	double operation(char pref, TStack<double, 100>& stack);
	functionBin* ukb=nullptr;
	functionUn* uku= nullptr;
	parser* ukp;//????????
private:
	
};

