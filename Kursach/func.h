#pragma once

inline int getPrior(const char  operetor) {
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
        return 5;
    }
    else if (operetor == '/') {
        return 5;
    }
    else if (operetor == ' ') {
        return -100;
    }
    else if (operetor == 'c') {
        return 10;
    }
    else if (operetor == 's') {
        return 10;
    }
    else if (operetor == 't') {
        return 10;
    }
    else if (operetor == 'w') {
        return 10;
    }
    else if (operetor == 'h') {
        return 10;
    }
    else if (operetor == 'n') {
        return 10;
    }
    else if (operetor == 'l') {
        return 10;
    }
    else if (operetor == 'g') {
        return 10;
    }
    else if (operetor == 'q') {
        return 10;
    }
    else if (operetor == '|') {
        return 2;
    }
    else if (operetor == '^') {
        return 6;
    }
    else {
        return -1;
    }
}

