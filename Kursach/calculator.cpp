#include "calculator.h"
#include"func.h"
#include"function.h"
#include"tstack.h"
#include"vector.h"

//************************************************
int max_size = 1000;
int sizeDisplay = 500;
int step = 50;

//***********************************************
double calculator::eval(std::string pref, double x)
{
    TStack<double, 100> stack1;
    double per = 0;
    int prior = 0;
    std::string chislo = "";
    int modul = 0;
    for (int i = 0; i < pref.length(); ++i) {
        prior = getPrior(pref[i]);
        if (prior == -100) { //space
            continue;
        }
        if (pref[i] == '-' && getPrior(pref[i - 1]) <= 1) {///
            chislo += pref[i];
            continue;
        } else if (prior == -1) { //number
            if (pref[i] == 'x') {
                stack1.push(x);
                continue;
            }
            else if (pref[i] == 'e') {
                stack1.push(2.71828182845904523);
                continue;
            }
            else if (pref[i] == 'p') {
                stack1.push(3.142857142857143);
                continue;
            }
            else {
                chislo += pref[i];
            }
            if (i + 1 != pref.length()) {
                if (getPrior(pref[i + 1]) == -1) {
                    continue;
                }
            }
            stack1.push(stoi(chislo));
        }
        else if (getPrior(pref[i]) == 2 && modul == 0) {
            modul += 1;

        }
        else {
            if (!(stack1.isEmpty())) {
                operation(pref[i], stack1);
            }
        }
        chislo = "";
    }
    return stack1.pop();
}

void calculator::toGive(std::string pref, MyVector &arrY, MyVector &arrX, double x1, double x2, double dep)
{
    double y1 = x1;
    double y2 = x2;
    for (double x = x1; x <= x2; x += dep) {
        double per = eval(pref, x);
        if (per<=y2 && per>=y1) {
            arrY.AddElemToMyVector(sizeDisplay-per*step);//Pochemy minus - hz
            arrX.AddElemToMyVector(sizeDisplay+x*step);
        }
    }
}

double calculator::operation(char pref, TStack<double, 100>& stack)
{
    if (getPrior(pref) <= 5 && getPrior(pref) > 0) {
        double const a = stack.pop();
        double const b = stack.pop();

        double per = this->ukb->operetor(pref, b, a);
        stack.push(per);
    }
    else if (getPrior(pref) == 6) {
        double const b = stack.pop();
        double per = this->uku->operetor(pref, b);
        stack.push(per);
    }
    else {
        return stack.pop();
    }
}
