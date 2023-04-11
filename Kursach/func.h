#pragma once

#include <string>


int getPrior(const char  operetor) {
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

