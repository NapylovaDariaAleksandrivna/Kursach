#pragma once
#include <cmath>
#include <string>

double operatoR(int a, std::string op) {
	if (op == "cos") {
		return cos(a);
	}
	else if (op == "sin") {
		return sin(a);
	}
	else if (op == "tg") {
		return tan(a);
	}
	else if (op == "ctg") {
		return 1 / tan(a);
	}
	else if (op == "ln") {
		return log(a);
	}
	else if (op == "log2") {
		return log2(a);
	}
	else if (op == "lg") {
		return log2(a);
	}
	else if (op == "sqrt") {
		return sqrt(a);
	}
	else if (op == "1/") {
		return 1 / (a);
	}
	else if (op == "-1/") {
		return -1 / (a);
	}
	else if (op == "|") {
		return abs(a);
	}
	return 0;
}


