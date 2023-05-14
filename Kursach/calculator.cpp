#include "calculator.h"

//************************************************
int max_size = 1000;
int sizeDisplay = max_size/2;
int step = 50;

//***********************************************
double calculator::eval(std::string pref, double x)
{
    std::string znaki = "+-*/^|()";
    std::string tsifri = "0123456789xep.,";
    std::string operUn = "cstl";
    TStack<double, 1000> stack1;
    std::string chislo = "";
    for (int i = 0; i < pref.length(); ++i) {

        if (pref[i]== ' ') { //space
            continue;
        }

        if (isOperation(pref[i], minus) && (tsifri.find(pref[i+1]) != std::string::npos || i==0)) {
            chislo += pref[i];
            continue;
        } else if (tsifri.find(pref[i]) != std::string::npos) {
            if (pref[i] == 'x') {
                if (chislo == "-") {
                    stack1.push(x * (-1));
                }
                else {
                    stack1.push(x);
                }
                continue;
            }
            else if (pref[i] == 'e') { 
                if (chislo == "-") {
                    stack1.push(2.71828182845904523*(-1));
                } else {
                    stack1.push(2.71828182845904523);
                }
                continue;
            }
            else if (pref[i] == 'p') {
                if (chislo == "-") {
                    stack1.push(3.142857142857143 * (-1));
                }
                else {
                    stack1.push(3.142857142857143);
                }
                continue;
            }
            else {
                chislo += pref[i];
                if (tsifri.find(pref[i + 1]) != std::string::npos) {
                    continue;
                }
            }           
            double b = stod(chislo);
            stack1.push(b);
            chislo = "";
            continue;

        } else {
            if (!(stack1.isEmpty())) { //operation

                double const a = stack1.pop();
                double b = 0;
                if (!stack1.isEmpty())
                    b = stack1.pop();
                stack1.push(operation(pref[i], a, b));
            }
            else
            {
                return stack1.pop();
            }
        }
    }
    return stack1.pop();
}

void calculator::toGive(std::string pref, int n)
{   
    if (pref == "Error") {
        return;
    }
    for (double x = -10  + 1; x <= 10  + 1; x += 0.02) {
        double per = eval(pref, x);

        this->arrY.AddElemToMyVector(sizeDisplay - per * step * pow(2, n));
        this->arrX.AddElemToMyVector(sizeDisplay + x * step * pow(2, n));
    }
}

double calculator::DegToRad(double D)
{
    double M = 3.14 / 180;
    return D * M;
};
double calculator::operation(char op, double b, double a)
{
    switch (op) {
    case plus:
        return a + b;
    case minus:
        return a - b;
    case multiply:
        return a * b;
    case share:
        if (a == 0) {
            return 0;
        }
        else
            return a / b;
    case degree:
        return pow(a, b);
    case cos_:
        return cos(DegToRad( 180 / 3.14 * b));
    case sin_:
        return sin(DegToRad(180 / 3.14 * b));
    case tg_:
        return tan(DegToRad(180 / 3.14 * b));
    case ctg_:
        return 1 / tan(DegToRad(180 / 3.14 * b));

    case ln_:
        if (b <= 0) {
            return -10;
        }
        else
            return log(b);
    case log_2:
        if (b <= 0) {
            return -10;
        }
        else
            return log2(b);
    case lg_:
        if (b <= 0) {
            return -10;
        }
        else
            return log10(b);
    case sqrt_:
        if (b < 0) {
            return 0;
        }
        else
            return sqrt(b);
    case modul:
        return abs(b);
    }
    return 0;
}

std::ostream& operator<<(std::ostream& out, const calculator& obj)
{
    obj.getArr();
    return out;
}
