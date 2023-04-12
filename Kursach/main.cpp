#include"calculator.h"

#include <iostream>
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
	parser obj;
	cin >> obj;
	cout << obj;
	calculator g;
	MyVector arrX(100), arrY(100);
	g.toGive(obj.getOut(),arrY,arrX,-5,5,-5,5,1);
	cout << arrX<<'\n';
	cout << arrY;
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

