#include"Tstack.h"
#include <string>

#pragma once

class calculate
{
public:
	int getPrior(char operetor);
	double operatoR(char pref, double a, double b);
	double DegToRad(double D);
	double Operator(char pref, double a, int& cur, std::string str);
	std::string toPstfx(std::string inf);
	double eval(std::string pref, double x);
private:

};
