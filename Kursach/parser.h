#pragma once
//DN
#include <string>
#include <iostream>
#include <vector>
#include <stack>

struct Element {
	std::string symbol;//��� �������� �� ������ ����������� �����
	int prioritet;//���������
};
class Parser {
	std::string intput; //������
	std::stack <Element> stek;//���� ��� ����������
	std::string output;// �������� ������
};