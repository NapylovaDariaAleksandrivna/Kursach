
#include"parser.h"

#include <iostream>
#include <string>
using namespace std;
#define Task2
#ifdef Task1
int main() {
	std::string inf = "x^2";
	std::string pref = toPstfx(inf);
	cout << inf << endl;
	cout << pref << endl;
	for (double i = 1; i <= 10; i += 1) {
		cout << eval(pref, i) << " " << i << std::endl;
	}
}
#endif // Task1


#ifdef Task2
int main() {
	std::string a = "2+2";
	parser obj;
	cin >> obj;
	cout << obj;
	obj.print(obj.getOut());
}
#endif // Task2

#ifdef Task3
int main() {
	parser b;
	calculate a;
	cout << b.eval("2 2 +", 1);
}
#endif // Task3


// уча знаков?
//”нарность

