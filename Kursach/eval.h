#pragma once
#include"Tstack.h"
#include"pstfx.h"
#include <string>

double operatoR(char pref, double a, double b) {
    switch (pref) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '^':
        return pow(a,b);
    case 'p':
        return log2(b)/log2(a);
    }
    return 0;
}
/*
double operatoR(char pref, double a) {
    switch (pref) {
    case 'c':
        return cos(a);
    case 's':
        return sin(a);
    case 't':
        return tan(a);
    case 'w':
        return 1 / tan(a);
    case 'n':
        return log(a);
    case 'l':
        return log2(a);
    case 'g':
        return log10(a);
    case 'q':
        return sqrt(a);
    case '|':
        return abs(a);
    }
    return 0;
}
*/
double eval(std::string pref){
    TStack<double, 100> stack1;
    double per = 0;
    int prior = 0;
    std::string chislo = "";
    for (int i = 0; i < pref.length(); ++i) {
        prior = getPrior(pref[i]);
        if (prior == -100) { //space
            continue;
        }
        if (prior == -1) { //number
            chislo += pref[i + 1];
            if (getPrior(pref[i + 1]) == -1) {
                continue;
            }
            stack1.push(stoi(chislo));
        }else { 
            if (!(stack1.isEmpty()) ){ 
                double a = stack1.pop();
                double b = stack1.pop();
                per = operatoR(b, a, pref[i]);
                stack1.push(per);
            }
        }
    }
    return stack1.pop();
}


