#include"pstfx.h"
#include"eval.h"
#include"parser.h"

#include <iostream>
#include <string>
using namespace std;
/*int main() {
	std::string inf = "x^2";
	std::string pref = toPstfx(inf);
	cout <<  inf << endl;
	cout << pref << endl;	
	for (double i = 1; i <= 10; i += 1) {
		cout << eval(pref, i) <<  " "<< i << std::endl;
	}
}
*/
int main() {
	std::string a = "2+2";
	parser obj();
	cout << obj;
}