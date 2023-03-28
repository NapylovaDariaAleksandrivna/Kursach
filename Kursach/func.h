#include"Tstack.h"
#include <string>
double getPrior(std::string operetor);

std::string infx2pstfx(std::string inf) {
    TStack<std::string, 100> stack;
    stack.push(" ");
    std::string output = "";
    int prior = 0;
    int priorOnHeight = -1;
    std::string operetor = "";

    for (int i = 0; i < inf.length();++i) {
        if (inf[i] = ' ')
            continue;
        else if ((inf[i] >= 40 and inf[i]) <= 47 or inf[i] == 94 or inf[i] == 124) {//znaki '^'and'|'
            operetor += inf[i];
        }
        else if (inf[i] >= 97 and inf[i] <= 122) {//bukvi
            operetor += inf[i];
            if ((inf[i + 1] == 's' or inf[i + 1] == 'c' or inf[i + 1] == 't' or inf[i + 1] == 'l') and (inf.length() <= i + 1)) {
                continue;
            }
        }
        else if (inf[i] >= 48 and inf[i] <= 57) {//tsifri
            operetor += inf[i];
            if ((inf[i + 1] >= 48 and inf[i + 1] <= 57) and (inf.length() <= i + 1)) {
                continue;
            }
        }
        else if (inf[i] == '\n') {//konets stroki
            while (getPrior(stack.get()) > 1) {
                output += stack.pop();
                output += " ";
            }
            stack.pop();
        }

        prior = getPrior(operetor);
        priorOnHeight = getPrior(stack.get());
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
        operetor = inf[i];
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

double getPrior(std::string operetor) {
    if (operetor == "(") {
        return 0;
    }
    else if (operetor == ")") {
        return 1;
    }
    else if (operetor == "+") {
        return 2;
    }
    else if (operetor == "-") {
        return 2;
    }
    else if (operetor == "*") {
        return 3;
    }
    else if (operetor == "/") {
        return 3;
    }
    else if (operetor == " ") {
        return -100;
    }
    else if (operetor == "cos") {
        return 5;
    }
    else if (operetor == "sin") {
        return 5;
    }
    else if (operetor == "tg") {
        return 5;
    }
    else if (operetor == "ctg") {
        return 5;
    }
    else if (operetor == "ln") {
        return 5;
    }
    else if (operetor == "log") {
        return 5;
    }
    else if (operetor == "lg") {
        return 5;
    }
    else if (operetor == "sqrt") {
        return 5;
    }
    else if (operetor == "|") {
        return 4;
    }
    else if (operetor == "^") {
        return 4;
    }
    return -1;
}
