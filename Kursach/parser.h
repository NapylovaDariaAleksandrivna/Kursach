#pragma once
//DN
#include <string>
#include <iostream>
#include <vector>
#include <stack>

struct Element {
	std::string symbol;//Для хранения не только однозначных чисел
	int prioritet;//Приоритет
};
class Parser {
	std::string intput; //Строка
	std::stack <Element> stek;//Стек для операторов
	std::string output;// Выходная строка
};