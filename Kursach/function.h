#pragma once
#include <cmath>
#include <string>
#include "tstack.h"

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
	else if (op == "lg") {
		return log2(a);
	}
	else if (op == "sqrt") {
		return sqrt(a);
	}
	/*else if (op == "1/") {
		return 1 / (a);
	}
	else if (op == "-1/") {
		return -1 / (a);
	}*/
	else if (op == "|") {
		return abs(a);
	}
	return 0;
}

int getPrior(std::string op) {
    if (op == "(") {
        return 0;
    }
    else if (op == ")") {
        return 1;
    }
    else if (op == "+") {
        return 2;
    }
    else if (op == "-") {
        return 2;
    }
    else if (op == "*") {
        return 3;
    }
    else if (op == "/") {
        return 3;
    }
    else if (op == " ") {
        return -100;
    }
    else if (op == "cos") {
        return 5;
    }
    else if (op == "sin") {
        return 5;
    }
    else if (op == "tg") {
        return 5;
    }
    else if (op == "ctg") {
        return 5;
    }
    else if (op == "ln") {
        return 5;
    }
    else if (op == "log") {
        return 5;
    }
    else if (op == "lg") {
        return 5;
    }
    else if (op == "sqrt") {
        return 5;
    }
    /*else if (op == "1/") {
        return 5;
    }
    else if (op == "-1/") {
        return 5;
    }*/
    else if (op == "|") {
        return 4;
    }
    else if (op == "^") {
        return 4;
    }
    return -1;
}

std::string infx2pstfx(std::string const inf) {
    TStack <std::string, 100> stack;
    std::string output = "";
    int prior = 0;
    int priorOnHeight = -1;
    std::string operetor = "";
    for (int op = 0; op <= inf.length(); ++op) {
        if (inf[op] >= 40 or inf[op] <= 47 or inf[op]==94 or inf[op]==124) {//znaki '^'and'|'
            operetor += inf[op];
        }
        else if (inf[op] >= 97 and inf[op] <= 122){//bukvi
            if (inf[op]=='s' or inf[op]=='c' or inf[op]=='t' or inf[op]=='l'){
                operetor = inf[op];
            } else {
                operetor += inf[op];
            }
            continue;
        }
        else if (inf[op] >= 48 and inf[op] <= 57) {//tsifri
            if (operetor[0] >= 48 and operetor[0] <= 57) {
                operetor += inf[op];
            } else {
                operetor = inf[op];
            }
            continue;
        }
        else if (inf[op] == '\n') {//konets stroki
            operetor = "\n";
        }
        
        prior = getPrior(operetor);
        priorOnHeight = getPrior(stack.get());
        if (operetor == "\n") { /* 1. Esli konets stroki*/
            while (getPrior(stack.get()) > 1) {
                output += stack.pop();
                output += " ";
            }
            stack.pop();
        }
        if (prior == -1) { /* 2. Esli chislo*/
            output += operetor;
            output += " ";
        }
        else if (prior == 0) { /* 3. Skobka ( */
            stack.push(operetor);
        }
        else if (prior == 1) { /* 4. Esli )*/
            while (getPrior(stack.get()) > 0) {
                output += stack.pop();
                output += " ";
            }
            stack.pop();
        }
        else if (prior > priorOnHeight || stack.isEmpty()) {
            stack.push(operetor);
        }
        else if (prior <= priorOnHeight && prior > 1) {
            while (getPrior(stack.get()) > 1) {
                output += stack.pop();
                output += " ";
            }
            stack.push(operetor);
        }
        operetor = "";
    }
    while (getPrior(stack.get()) > 1) {
        output += stack.pop();
        output += " ";
    }
    std::string out = "";
    for (int i = 0; i < output.length() - 1; ++i) {
        out += output[i];
    }
    return out;
}
int operatoR(int a, int b, std::string inf[op]) {
    if (inf[op] == "+") {
        return a + b;
    }
    else if (inf[op] == "-") {
        return a - b;
    }
    else if (inf[op] == "*") {
        return a * b;
    }
    else if (inf[op] == "/") {
        return a / b;
    }
    else if (inf[op] == "^") {
        return pow(a, b);
    }
    else if (inf[op] == "log") {
        return log2(b)/log2(a);
}

int eval(std::string pref) {
    TStack<int, 100> stack1;
    int per = 0;
    int prior = 0;
    for (auto& inf[op] : pref) {
        prior = getPrior(inf[op]);
        if (prior == -100) { //space
            continue;
        }
        if (prior == -1) { //number
            stack1.push(inf[op] - 48);
        }
        else {
            int hz = 0;
            while (!(stack1.isEmpty() + hz)) {
                hz += 1;
                int a = stack1.pop();
                int b = stack1.pop();
                per = operatoR(b, a, inf[op]);
                stack1.push(per);
            }
        }
    }
    return stack1.pop();
}
