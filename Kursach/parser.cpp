#include "parser.h"
#include <iostream>
#include<string>	
#include"pstfx.h"
#include"eval.h"
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
	out << "Input: " << obj.GetIn() << '\n' << "Output: " << obj.GetOut();
	return out;
}

