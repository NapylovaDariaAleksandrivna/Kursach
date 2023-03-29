#pragma once
#include"Tstack.h"
#include <string>


int getPrior(char operetor) {
    if (operetor == '(') {
        return 0;
    }
    else if (operetor == ')') {
        return 1;
    }
    else if (operetor == '+') {
        return 2;
    }
    else if (operetor == '-') {
        return 2;
    }
    else if (operetor == '*') {
        return 3;
    }
    else if (operetor == '/') {
        return 3;
    }
    else if (operetor == ' ') {
        return -100;
    }
    else if (operetor == 'c') {
        return 5;
    }
    else if (operetor == 's') {
        return 5;
    }
    else if (operetor == 't') {
        return 5;
    }
    else if (operetor == 'w') {
        return 5;
    }
    else if (operetor == 'n') {
        return 5;
    }
    else if (operetor == 'l') {
        return 5;
    }
    else if (operetor == 'g') {
        return 5;
    }
    else if (operetor == 'q') {
        return 5;
    }
    else if (operetor == '|') {
        return 5;
    }
    else if (operetor == '^') {
        return 5;
    }
    else {
        return -1;
    }
}

//"cos"=c "sin"=s "tg"= t "ctg"=w "ln"= n "log2"=l "lg"= g "sqrt"=q
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
        return pow(a, b);
    case 'p':
        return log2(b) / log2(a);
    }
    return 0.0;
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