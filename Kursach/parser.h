#include <iostream>
#include <string>
#include "calculate.h"
#pragma once



class parser : public calculate {
private:
	std::string input;
	std::string output;
public:
	void setIn(std::string& input) { this->input = input; }
	void setOut(std::string& output) { this->output = output; }
	std::string getIn()const { return input; }
	std::string getOut()const { return output; }
	parser(std::string in) :input(in){};
	parser() {};
	void print(std::string pref, double x1=-5, double x2=5, double y1=-5, double y2=5, double dep = 1);
};
std::ostream& operator<< (std::ostream& out, const parser& obj);
std::istream& operator>> (std::istream& in,  parser& obj);