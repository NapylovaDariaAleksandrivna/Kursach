#include <iostream>
#include <string>
#include"pstfx.h"
#include"eval.h"
#pragma once
class parser
{
private:
	std::string input;
	std::string output;
public:

	//void print(parser obj);
	void setIn(std::string& input) { this->input = input; }
	void setOut(std::string& output) { this->output = output; }
	std::string GetIn()const { return input; }
	std::string GetOut()const { return output; }
	parser(std::string in, std::string out) :input(in), output(out) {};
	parser() {};
	
};
std::ostream& operator<< (std::ostream& out, const parser& obj);
std::istream& operator>> (std::istream& in,  parser& obj);