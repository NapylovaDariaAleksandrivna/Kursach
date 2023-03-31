#include "calculate.h"
#include"Tstack.h"
#include <string>


int calculate::getPrior(char operetor) {
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
double calculate::operatoR(char pref, double a, double b) {
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

double calculate::DegToRad(double D)
{
    double M = 3.14 / 180;
    return D * M;
};

double calculate::Operator(char pref, double a, int& cur, std::string str) {
    switch (pref) {
    case 'c':
        return cos(DegToRad(a));
    case 's':
        return sin(DegToRad(a));
    case 't':
        if (int(cos(DegToRad(a)) * 100) == 0) {
            cur = str.length() + 100;
            return 0;
        }
        else {
            return tan(DegToRad(a));//не существует при а=90 и 270
        }
    case 'w':
        if (int(sin(DegToRad(a)) * 100) == 0) {
            cur = str.length() + 100;
            return 0;
        }
        else {
            return 1 / tan(DegToRad(a));//не существует при а=0 и 180
        }
    case 'n':
        if (a <= 0) {
            cur = str.length() + 100;
            return 0;
        }
        else
            return log(a);//не существует при а<=0
    case 'l':
        if (a <= 0) {
            cur = str.length() + 100;
            return 0;
        }
        else
            return log2(a);//не существует при а<=0
    case 'g':
        if (a <= 0) {
            cur = str.length() + 100;
            return 0;
        }
        else
            return log10(a);//не существует при а<=0
    case 'q':
        if (a < 0) {
            cur = str.length() + 100;
            return 0;
        }
        else
            return sqrt(a);//не существует при а<0
    case '|':
        return abs(a);//не работает с модулем в модуле, типо |x+3*x|
    }
    return 0;
}

std::string calculate::toPstfx(std::string inf) {
    TStack<char, 100> stack;
    std::string output = "";
    int prior = 0;
    int priorOnHeight = -1;
    char operetor;
    int modul = 0;
    for (int i = 0; i < inf.length(); ++i) {
        if ((inf[i] >= 40 and inf[i] <= 47) or inf[i] == 94 or inf[i] == 124) {//znaki '^'and'|'
            operetor = inf[i];
        }
        else if (inf[i] >= 97 and inf[i] <= 122 and inf[i] != 'x' and inf[i] != 'e' and inf[i] != 'p') {//bukvi
            if (inf[i] == 'c') {
                if (inf[i + 1] == 'o') {
                    operetor = 'c';
                    i += 2;
                }
                else {
                    operetor = 'w';
                    i += 2;
                }
            }
            else if (inf[i] == 's') {
                if (inf[i + 1] == 'i') {
                    operetor = 's';
                    i += 2;
                }
                else {
                    i += 3;
                    operetor = 'q';
                }
            }
            else if (inf[i] == 't') {
                operetor = 't';
                i += 1;
            }
            else if (inf[i] == 'l') {
                if (inf[i + 1] == 'o') {
                    i += 2;
                    operetor = 'l';
                }
                else if (inf[i + 1] == 'g') {
                    i += 1;
                    operetor = 'g';
                }
                else {
                    operetor = 'n';
                    i += 1;
                }
            } //"cos"=c "sin"=s "tg"= t "ctg"=w "ln"= n "log2"=l "lg"= g "sqrt"=q
        }
        else if ((inf[i] >= 48 and inf[i] <= 57) or inf[i] == 'x' or inf[i] == 'e' or inf[i] == 'p') {//tsifri
            output += inf[i];
            if (inf[i] == 'p')
                i += 1;
            if ((inf[i + 1] >= 48 and inf[i + 1] <= 57) and (i + 1 <= inf.length())) {
                continue;
            }
            output += " ";
            continue;
        }
        else if (inf[i] == '\n') {//konets stroki
            while (getPrior(stack.get()) > 1) {
                output += stack.pop();
                output += " ";
            }
            stack.pop();
            std::string out = "";
            for (int i = 0; i < output.length() - 1; ++i) {
                out += output[i];
            }
            return out;
        }

        prior = getPrior(operetor);
        priorOnHeight = getPrior(stack.get());
        if (prior == 0) { // 3. Skobka ( 
            stack.push(operetor);
        }
        else if (prior == 1) { // 4. Esli )
            while (getPrior(stack.get()) > 0) {
                output += stack.pop();
                output += " ";
            }
            stack.pop();
        }


        else if (prior == 2 and modul == 0) { // 5. Esli | v nachale
            stack.push(operetor);
            modul += 1;
        }
        else if (prior == 2 and modul == 1) { // 6. Esli | v kontse
            while (getPrior(stack.get()) > 2) {
                output += stack.pop();
                output += " ";
            }
            output += "| ";
            stack.pop();
            modul -= 1;
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
        operetor = ' ';
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

double calculate::eval(std::string pref, double x) {
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
            if (getPrior(pref[i + 1]) == -1) {
                continue;
            }
            stack1.push(stoi(chislo));
        }
        else if (getPrior(pref[i]) == 2 && modul == 0) {
            modul += 1;

        }
        else {
            if (!(stack1.isEmpty())) {
                if (getPrior(pref[i]) < 5) {
                    double const a = stack1.pop();
                    double const b = stack1.pop();

                    per = operatoR(pref[i], b, a);
                    stack1.push(per);
                }
                else {
                    double const b = stack1.pop();

                    per = Operator(pref[i], b, i, pref);
                    stack1.push(per);
                }

            }
        }
        chislo = "";
    }
    return stack1.pop();
}
