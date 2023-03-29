#pragma once
#include <string>
class parser {
private:
	std::string input;
	std::string output;
public:
	void SetInput(std::string input) { this->input = input; };
	void SetOutput(std::string output) { this->output = output; };
	std::string GetInput()const { return input; }
	std::string GetOutput()const { return output; }
	parser():input(""), output("") {}
	parser(std::string in, std::string out = "");
};
