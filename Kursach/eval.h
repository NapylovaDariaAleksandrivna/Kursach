#pragma once
#include"Tstack.h"
#include <string>
#include"func.h"

double eval(std::string pref, double x){
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
        if (prior == -1) { //number
            if (pref[i]=='x') {
                stack1.push(x);
                continue;
            } else if (pref[i] == 'e') {
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
            if (getPrior(pref[i + 1]) == -1) {
                continue;
            }
            stack1.push(stoi(chislo));
        }
        else if (getPrior(pref[i])==2 && modul==0) {
            modul+=1;

        }
        else {
            if (!(stack1.isEmpty()) ){ 
                if (getPrior(pref[i]) < 5) {
                    double const a = stack1.pop();
                    double const b = stack1.pop();

                    per = operatoR(pref[i], b, a);
                    stack1.push(per);
                }
                else {
                    double const b = stack1.pop();

                    per = Operator(pref[i], b);
                    stack1.push(per);
                }

            }
        }
        chislo = "";
    }
    return stack1.pop();
}


