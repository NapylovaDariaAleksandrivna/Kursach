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
    case braceOpen:
        return 0;
    case braceClose:
        return 1;
    case modul:
        return 2;
    case plus:
        return 3;
    case minus:
        return 3;
    case multiply:
        return 4;
    case share:
        return 4;
    case degree:
        return 5;
    case cos_:
        return 6;
    case sin_:
        return 6;
    case tg_:
        return 6;
    case ctg_:
        return 6;
    case ln_:
        return 6;
    case log_2:
        return 6;
    case lg_:
        return 6;
    case sqrt_:
        return 6;
    default:
        return -1;
    }
    
}

