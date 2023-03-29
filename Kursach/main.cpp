#include"pstfx.h"
#include"eval.h"
//#include"parser.h"

#include <iostream>
#include <string>
using namespace std;
int main() {
	std::string inf = "tg(x)";
	std::string pref = toPstfx(inf);
	cout <<  inf << endl;
	cout << pref << endl;	
	for (double i = -360; i <= 360; i += 90) {
		cout << eval(pref, i) <<  " "<< i << std::endl;
	}
}
/*
int main() {
	parser obj("2+2");
}*/