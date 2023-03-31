#include "parser.h"
#include "calculate.h"
#include <iostream>
#include<string>	

std::istream& operator>>(std::istream& in, parser& obj)
{
	std::string a;
	calculate m;
	in >> a;
	obj.setIn(a);
	std::string b = m.toPstfx(a);
	obj.setOut(b);
	return in;
}

std::ostream& operator<<(std::ostream& out, const parser& obj)
{
	out << "Input: " << obj.GetIn() << '\n' << "Output: " << obj.GetOut();
	return out;
}

