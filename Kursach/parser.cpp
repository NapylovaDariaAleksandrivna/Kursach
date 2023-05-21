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
    if (b!="Error")
        obj.setOut(b);
	return in;
}

std::ostream& operator<<(std::ostream& out, const parser& obj)
{
	out << "Input: " << obj.getIn() << '\n' << "Output: " << obj.getOut()<<std::endl;
	return out;
}

std::string parser::toPstfx(std::string inf)const {
    if (inf == " " or inf=="") {
        return"Error";
    }
    TStack<char, 100> stack;
    std::string output = "";
    int prior = 0;
    int priorOnHeight = -1;

    char operetor;
    int modulC = 0;

    std::string znaki = "+-*/^|()";
    std::string tsifri = "0123456789xep.,";
    std::string operUn = "cstl";

    for (int i = 0; i < inf.length(); ++i) {

        if (inf[i] == ' ')
            continue;

        if (znaki.find((inf[i])) != std::string::npos) {
            
            if (isOperation(inf[i], minus_)) {

                if (i == 0) {
                    output += inf[i];
                    continue;
                }
                else if (isOperation(inf[i-1], braceOpen)) {
                    output += inf[i];
                    continue;
                }
            }
            operetor = inf[i];
            std::string strPosle = "0123456789xepcstl(";
            std::string strDo  =   "0123456789xepsngt)";
            if ((!isOperation(inf[i], braceOpen)) && (!isOperation(inf[i], braceClose)) &&
                (!isOperation(inf[i], modul)) &&
                ((i == 0) || (i == inf.length() - 1) || (strPosle.find((inf[i + 1])) == std::string::npos) ||
                                                           (strDo.find((inf[i - 1])) == std::string::npos))) {
                return "Error";
            }
            //Обработака исключений
        }
        else if (operUn.find((inf[i])) != std::string::npos) {
            if (inf[i] == 'c') {
                if (inf[i + 1] == 'o') {
                    operetor = 'c';
                    i += 2;
                }
                else if (inf[i + 1] == 't'){
                    operetor = 'w';
                    i += 2;
                }
                else {
                    return "Error";
                }
            }
            else if (inf[i] == 's') {
                if (inf[i + 1] == 'i') {
                    operetor = 's';
                    i += 2;
                }
                else if (inf[i + 1] == 'q') {
                    i += 3;
                    operetor = 'q';
                }
                else {
                    return "Error";
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
                else if (inf[i + 1] == 'n') {
                    operetor = 'n';
                    i += 1;
                }
                else {
                    return "Error";
                }
            }
            else {
                return "Error";
            }
        }
        else if (tsifri.find((inf[i])) != std::string::npos) {
            output += inf[i];
            if (inf[i] == 'p' and inf[i+1] == 'i') {
                i += 1;
                output += " ";
                continue;
            } else if ((inf[i] == 'p' and inf[i + 1] != 'i') or ((inf[i] == '.' || inf[i] == ',') && 
                (tsifri.find((inf[i + 1])) == std::string::npos || tsifri.find((inf[i - 1])) == std::string::npos))) {
                return "Error";
            } 

            if ((tsifri.find((inf[i+1])) != std::string::npos) && (i + 1 <= inf.length())) {
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
        else {
            return "Error";
        }

        prior = getPrior(operetor);
        priorOnHeight = getPrior(stack.get());

        if (isOperation(operetor, braceOpen)) { // 3. Skobka ( 
            stack.push(operetor); 
        }
        else if (isOperation(operetor, braceClose)) { // 4. Esli )
            while (getPrior(stack.get()) > 0) {
                output += stack.pop();
                output += " ";
            }
            stack.pop();
        }
        else if (isOperation(operetor, modul) && modulC == 0) { // 5. Esli | v nachale
            stack.push(operetor);
            modulC += 1;
        }
        else if (isOperation(operetor, modul) && modulC == 1) { // 6. Esli | v kontse
            while (getPrior(stack.get()) > 2) {
                output += stack.pop();
                output += " ";
                modulC -= 1;
            }
            output += "| ";
            stack.pop();
            modulC -= 1;
        }


        else if (prior > priorOnHeight || stack.isEmpty()) {
            stack.push(operetor);
        }
        else if (prior <= priorOnHeight && !isOperation(operetor, braceClose) && !isOperation(operetor, braceOpen)) {
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
    if (output==" " or output == "") {
        return"Error";
    }
    return output;
}

void parser::setIn(std::string& input)
{
    this->input = input;
    std::string b = this->toPstfx(input);
    if (b != "Error" or input.length()>100)
        this->output = b;
    else
        this->output = "Error";

}
