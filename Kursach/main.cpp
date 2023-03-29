#include"pstfx.h"
#include"eval.h"
//#include"parser.h"

#include <iostream>
#include <string>
using namespace std;
int main() {
	std::string inf = "sqrt(x)";
	std::string pref = toPstfx(inf);
	cout <<  inf << endl;
	cout << pref << endl;	
	for (double i = -90; i <= 90; i += 30) {
		cout << eval(pref, i) << " ";
	}
}