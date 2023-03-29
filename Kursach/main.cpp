#include"pstfx.h"
#include"eval.h"
//#include"parser.h"

#include <iostream>
#include <string>
using namespace std;
int main() {
	std::string inf = "pi*1";
	std::string pref = toPstfx(inf);
	cout <<  inf << endl;
	cout << pref << endl;	
	for (double i = -1; i <= 1; i += 0.5) {
		cout << eval(pref, i) <<  " "<< i << std::endl;
	}
}