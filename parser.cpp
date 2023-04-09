#include "parser.h"
#include "func.h"
#include <iostream>
#include<string>	

std::istream& operator>>(std::istream& in, parser& obj)
{
	std::string a;
	in >> a;
	obj.setIn(a);
	std::string b = toPstfx(a);
	obj.setOut(b);
	return in;
}

std::ostream& operator<<(std::ostream& out, const parser& obj)
{
	out << "Input: " << obj.getIn() << '\n' << "Output: " << obj.getOut()<<std::endl;
	return out;
}

void parser::print(std::string pref, double x1 , double x2, double y1 , double y2 , double dep) 
{
	for (int x = x1; x <= x2; x+=dep) {
		for (int y = y1; y <= y2; ++y) {
			double a = eval(pref, x);
			if(a==y)
				std::cout << "y= " << a << ", x= " << x << std::endl;
		}
	}
}
