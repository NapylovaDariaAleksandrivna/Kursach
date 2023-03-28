#include"func.h"
//#include"parser.h"

#include <iostream>
#include <string>
using namespace std;
int main() {
	string str="(2 + 2) * 2";
	//parser object;
	//object.SetInput(str);
	//cout << object.GetInput() << endl;
	cout << infx2pstfx(str) << endl;
}