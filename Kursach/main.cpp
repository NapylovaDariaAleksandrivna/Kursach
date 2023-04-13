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
	double x1 = -20, x2 = 20, y1 = -20, y2 = 20, dep = 0.20;
	parser obj;
	cin >> obj;
	cout << obj;
	calculator g;
	MyVector arrX(100), arrY(100);
	g.toGive(obj.getOut(),arrY,arrX,x1,x2,y1,y2,dep);
	cout << "x " << arrX << '\n';
	cout << "y " << arrY;
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

