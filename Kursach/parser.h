#pragma once
//DN
#include <string>
#include <map>
#include "tstack.h"
#include <cmath>

class Parser {
private:
	std::string input;
	std::string output;
public:
	void SetInput(std::string input) { this->input = input; };
	void SetOutput(std::string output) { this->output = output; };
	std::string GetInput()const { return input; }
	std::string GetOutput()const { return output; }
};
std::istream& operator>> (std::istream& in, std::string input);