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
        return 3;
    }
    else if (operetor == '-') {
        return 3;
    }
    else if (operetor == '*') {
        return 4;
    }
    else if (operetor == '/') {
        return 4;
    }
    else if (operetor == ' ') {
        return -100;
    }
    else if (operetor == 'c') {
        return 6;
    }
    else if (operetor == 's') {
        return 6;
    }
    else if (operetor == 't') {
        return 6;
    }
    else if (operetor == 'w') {
        return 6;
    }
    else if (operetor == 'h') {
        return 6;
    }
    else if (operetor == 'n') {
        return 6;
    }
    else if (operetor == 'l') {
        return 6;
    }
    else if (operetor == 'g') {
        return 6;
    }
    else if (operetor == 'q') {
        return 6;
    }
    else if (operetor == '|') {
        return 2;
    }
    else if (operetor == '^') {
        return 4;
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
        if (b == 0) {
            return a;
        }
        else
            return a / b; //не существует при b=0
    case '^':
        return pow(a, b);
    case 'h':
        return log2(b) / log2(a);//не существует при а<=0 Пока не реализована
    }
    return 0.0;
}

double DegToRad(double D)
{
    double M = 3.14 / 180;
    return D * M;
};

double Operator(char pref, double a) {
    switch (pref) {
    case 'c':
        return cos(DegToRad(a));
    case 's':
        return sin(DegToRad(a));
    case 't':
        if (int(cos(DegToRad(a)))==0){
            throw std::string("tg dosen't be");
        }
        else {
            return tan(DegToRad(a));//не существует при а=90 и 270
        }
    case 'w':
        if (int(sin(DegToRad(a))) == 0) {
            throw std::string("ctg dosen't be");
        }
        else {
            return 1 / tan(DegToRad(a));//не существует при а=0 и 180
        }   
    case 'n':
        if (a <= 0) {
            throw std::string("ln dosen't be");
        }else
            return log(a);//не существует при а<=0
    case 'l':
        if (a <= 0) {
            throw std::string("log2 dosen't be");
        }
        else
            return log2(a);//не существует при а<=0
    case 'g':
        if (a <= 0) {
            throw std::string("lg dosen't be");
        }
        else
            return log10(a);//не существует при а<=0
    case 'q':
        if (a < 0) {
            throw std::string("sqrt dosen't be");
        }
        else
            return sqrt(a);//не существует при а<0
    case '|':
        return abs(a);//не работает с модулем в модуле, типо |x+3*x|
    }
    return 0;
}

