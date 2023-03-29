#include "parser.h"
#include"pstfx.h"
#include "func.h"
#include<iostream>
parser::parser(std::string in, std::string out)
{
	input = in;
	output = out;
}

std::istream& operator>>(std::istream& cin, parser& peremennay)
{
    std::string inf = "";
    cin >> inf;
    peremennay.SetInput(inf);
    inf = toPstfx(inf);
    //peremennay.SetOutput();
    return cin;
}

std::istream& operator<<(std::istream& out, parser& peremennay)
{
    std::cout << peremennay.GetInput() << '/n';
    std::cout << peremennay.GetOutput() << '/n';
    return out;
}
