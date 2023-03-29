#pragma once
#include"Tstack.h"
#include <string>
#include"func.h"

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
            chislo += pref[i];
            if (getPrior(pref[i + 1]) == -1) {
                continue;
            }
            stack1.push(stoi(chislo));
        }else { 
            if (!(stack1.isEmpty()) ){ 
                double const a = stack1.pop();
                double const b = stack1.pop();
                per = operatoR(pref[i],b, a);
                stack1.push(per);
            }
        }
        chislo = "";
    }
    return stack1.pop();
}


