#include "parser.h"
#include"tstack.h"
#include "func.h"
#include <iostream>
#include<string>	

std::istream& operator>>(std::istream& in, parser& obj)
{
	std::string a;
    getline(in, a);
	obj.setIn(a);
	std::string b = obj.toPstfx(a);
	obj.setOut(b);
	return in;
}

std::ostream& operator<<(std::ostream& out, const parser& obj)
{
	out << "Input: " << obj.getIn() << '\n' << "Output: " << obj.getOut()<<std::endl;
	return out;
}

std::string parser::toPstfx(std::string inf) {//хреново воспринимает пробелы/ не считет нормально
    TStack<char, 100> stack;
    std::string output = "";
    int prior = 0;
    int priorOnHeight = -1;
    char operetor;
    int modul = 0;
    for (int i = 0; i < inf.length(); ++i) {
        if (inf[i] == ' ')
            i += 1;
        if ((inf[i] >= 40 && inf[i] <= 47) || inf[i] == 94 || inf[i] == 124) {//znaki '^'&&'|'
            if (inf[i] == '-') {

                if (i == 0) {
                    output += inf[i];
                    continue;
                }
                else if (getPrior(inf[i - 1]) == 0 ) {
                    output += inf[i];
                    continue;
                }
            }
            operetor = inf[i];
        }
        else if (inf[i] >= 97 && inf[i] <= 122 && inf[i] != 'x' && inf[i] != 'e' && inf[i] != 'p') {//bukvi
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
        else if ((inf[i] >= 48 && inf[i] <= 57) || inf[i] == 'x' || inf[i] == 'e' || inf[i] == 'p') {//tsifri
            output += inf[i];
            if (inf[i] == 'p')
                i += 1;
            if ((inf[i + 1] >= 48 && inf[i + 1] <= 57) && (i + 1 <= inf.length())) {
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


        else if (prior == 2 && modul == 0) { // 5. Esli | v nachale
            stack.push(operetor);
            modul += 1;
        }
        else if (prior == 2 && modul == 1) { // 6. Esli | v kontse
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
