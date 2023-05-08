#pragma once


enum Operations : int
{
    other = -1,
    braceOpen = static_cast < int>('('), braceClose = static_cast < int>(')'),
    modul =static_cast < int>('|'),
    minus = static_cast < int>('-'), plus = static_cast < int>('+'),
    multiply = static_cast < int>('*'), share = static_cast < int>('/'),
    degree = static_cast < int>('^'),

    cos_ = static_cast < int>('c'), 
    ctg_ = static_cast < int>('w'), 
    sin_ = static_cast < int>('s'), 
    sqrt_ = static_cast < int>('q'), 
    tg_ = static_cast < int>('t'), 
    ln_ = static_cast < int>('n'), 
    lg_ = static_cast < int>('g'), 
    log_2 = static_cast < int>('l')
};

inline bool isOperation(char& right, Operations left) {
    return right == left;
}

inline int getPrior(const char  operetor) {
    switch (operetor) {
    case '(':
        return 0;
    case ')':
        return 1;
    case '|':
        return 2;
    case '+':
        return 3;
    case '-':
        return 3;
    case '*':
        return 4;
    case '/':
        return 4;
    case '^':
        return 5;
    case 'c':
        return 6;
    case 's':
        return 6;
    case 't':
        return 6;
    case 'w':
        return 6;
    case 'n':
        return 6;
    case 'l':
        return 6;
    case 'g':
        return 6;
    case 'q':
        return 6;
    default:
        return -1;
    }
    
}

