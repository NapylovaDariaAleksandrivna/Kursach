#include"pstfx.h"
#include"eval.h"
//#include"parser.h"

#include <iostream>
#include <string>
using namespace std;
int main() {
	std::string inf = "89+41";
	std::string pref = toPstfx(inf);
	cout <<  inf << endl;
	cout << pref << endl;
	cout << eval(pref) << endl;
	for (double i = -3.0; i <= 3.0; i += 0.1) {
		break;
	}
}