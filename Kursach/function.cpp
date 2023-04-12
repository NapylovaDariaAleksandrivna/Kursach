#include "function.h"
#include<cmath>
double functionBin::operetor(char pref, double a, double b)
{
    switch (pref) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        if (a == 0) {
            return b;
        }
        else
            return b / a; 
    case '^':
        return pow(a, b);
    case 'h':
        return log2(b) / log2(a);
    }
    return 0;
}
double DegToRad(double D)
{
    double M = 3.14 / 180;
    return D * M;
};
double functionUn::operetor(char pref, double a)
{
    switch (pref) {
    case 'c':
        return cos(DegToRad(a));
    case 's':
        return sin(DegToRad(a));
    case 't':
        if (int(cos(DegToRad(a)) * 100) == 0) {
            //cur = ukp->getOut().length() + 100;
            return 0;
        }
        else {
            return tan(DegToRad(a));
        }
    case 'w':
        if (int(sin(DegToRad(a)) * 100) == 0) {
            //cur = str.length() + 100;
            return 0;
        }
        else {
            return 1 / tan(DegToRad(a));
        }
    case 'n':
        if (a <= 0) {
            //cur = str.length() + 100;
            return 0;
        }
        else
            return log(a);
    case 'l':
        if (a <= 0) {
            //cur = str.length() + 100;
            return 0;
        }
        else
            return log2(a);
    case 'g':
        if (a <= 0) {
            //cur = str.length() + 100;
            return 0;
        }
        else
            return log10(a);
    case 'q':
        if (a < 0) {
            //cur = str.length() + 100;
            return 0;
        }
        else
            return sqrt(a);
    case '|':
        return abs(a);
    }
    return 0;
}

