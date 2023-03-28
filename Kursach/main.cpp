#include"func.h"
//#include"parser.h"

#include <iostream>
#include <string>
using namespace std;
int main() {
	std::string inf = "8*(3+7)/2-(3+7)*9";
	//parser object;
	//object.SetInput(inf);
	//cout << object.GetInput() << endl;
	cout << infx2pstfx(inf) << endl;
}