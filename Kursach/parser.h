#include <iostream>
#include <string>
#pragma once



class parser {
private:
	std::string input;
	std::string output;
	
public:
	
	std::string toPstfx(std::string inf)const;
	void setIn(std::string& input);
	void setOut(std::string& output) { this->output = output; }
	std::string getIn()const { return input; }
	std::string getOut()const { return output; }
	parser(std::string in) :input(in),output(toPstfx(in))
	{};
	parser() {};
};
std::ostream& operator<< (std::ostream& out, const parser& obj);
std::istream& operator>> (std::istream& in,  parser& obj);