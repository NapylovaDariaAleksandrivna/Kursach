#pragma once
#include "parser.h"
#include"function.h"
#include <iostream>
#include<string>	
class calculator
{
public:
	double eval(std::string pref, double x);
	void toGive(std::string pref, double x1, double x2, double y1, double y2, double dep);
	double operation(char pref, TStack<double, 100>& stack);
	functionBin* ukb=nullptr;
	functionUn* uku= nullptr;
	parser* ukp;//????????
private:
	
};

