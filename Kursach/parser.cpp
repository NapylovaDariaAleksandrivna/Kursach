#include "parser.h"
#include "function.h"
#include <string>
#include <map>
#include "tstack.h"
#include <cmath>

std::istream& operator>> (std::istream& in, Parser& peremennay) {
    std::string inf = "";
    in >> inf;
    peremennay.SetInput(inf);
    peremennay.SetOutput(infx2pstfx(inf));
    return in;
}

