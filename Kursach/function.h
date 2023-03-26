#pragma once
#include <cmath>

int operatoR(int a, std::string op) {
    switch (op) {
    case 'cos':
        return cos(a);
    case 'sin':
        return sin(a);
    case 'tg':
        return tan(a);
    case 'ctg':
        return 1/tan(a);
    case 'ln':
        return log(a);
    case 'log2':
        return log2(a);
    case 'lg':
        return log10(a);
    case 'sqrt':
        return sqrt(a);
    case '1/':
        return (1/a);
    case '-1/':
        return (-1 / a);
    case '^2':
        return pow(a, 2);
    case '^3':
        return pow(a, 3);
    case '|':
        return abs(a);
    }
    return 0;
}