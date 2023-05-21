#pragma once
#include<SFML/Graphics.hpp>
#include "vector.h"
#include <stdlib.h>
using namespace sf;
template<typename T, int max_size>
inline void draw(VertexArray &myLines1, VertexArray &myLines2, int hz, MyVector<T, max_size>& arrX, MyVector<T, max_size>& arrY) {
	for (int i = 0; i < arrX.GetSize() - 1; i++) {
		myLines1[i].position = Vector2f(arrX[i], arrY[i]);
		if (abs(arrY[i] - arrY[i + 1]) > hz) {
			myLines1[i].color = Color(255, 192, 203, 0);
		}
		else myLines1[i].color = Color::Red;
	} for (int i = 1; i < arrX.GetSize() - 2; i++) {
		myLines2[i + 1].position = Vector2f(arrX[i], arrY[i]);
		if (abs(arrY[i] - arrY[i + 1]) > hz) {
			myLines2[i + 1].color = Color(255, 192, 203, 0);
		}
		else myLines2[i + 1].color = Color::Red;
	}
}

void GribPole(VertexArray &verticalGrib, VertexArray &horizontalGrib, RectangleShape &lineY, RectangleShape &lineX, RectangleShape &pole, int Xsize, int Ysize) {
	for (int i = 0, y = 0, x = 0; i < 50; i += 2, y += 50, x += 50)
	{
		verticalGrib[i].position = Vector2f(0, 50 + y);
		verticalGrib[i + 1].position = Vector2f(Xsize / 2, 50 + y);

		horizontalGrib[i].position = Vector2f(50 + x, 0);
		horizontalGrib[i + 1].position = Vector2f(50 + x, Ysize);
	}
	lineX.setPosition(0, 498);
	lineX.setFillColor(Color::Black);

	lineY.setPosition(498, 0);
	lineY.setFillColor(Color::Black);

	pole.setPosition(Xsize / 2, 0);
	pole.setFillColor(Color::Black);
}
void isPressed(VertexArray& lineOne, VertexArray& lineTwo, VertexArray& lineThree, VertexArray& lineFour, VertexArray& lineFive, VertexArray& lineSix, std::string stringValue, std::string& error, double Ysize, int n) {
	VertexArray myLines1(Lines, 1000);
	VertexArray myLines2(Lines, 1000);

	//*****************************

	VertexArray myLines3(Lines, 1000);
	VertexArray myLines4(Lines, 1000);
	VertexArray myLines5(Lines, 1000);
	VertexArray myLines6(Lines, 1000);
	//*****************************

	parser obj(stringValue);
	calculator objC(stringValue, n);
	std::cout << obj;
	if (objC.GetSize() == 0 or obj.getOut() == "Error") {
		error = "Error";
		lineOne.clear();
		lineTwo.clear();

		//*****************************
		lineThree.clear();
		lineFour.clear();
		lineFive.clear();
		lineSix.clear();
		//*****************************

		return;
	}

	int const hz = 50;
	draw(myLines1, myLines1, hz, objC.arrX, objC.arrY);

	//*****************************
	draw(myLines3, myLines4, hz, objC.arrX, objC.arrY);
	draw(myLines5, myLines6, hz, objC.arrX, objC.arrY);
	//*****************************

	error = "";
	lineOne = myLines1;
	lineTwo = myLines2;

	//*****************************
	lineThree = myLines3;
	lineFour = myLines4;
	lineFive = myLines5;
	lineSix = myLines6;
	//*****************************
}

double roundDouble(double val) {
	
	std::string s = std::to_string(val);

	if (s[s.size() - 1] == '0')
		for (size_t i = s.size() - 1; s[i] == '0'; i--)
			s.erase(i, 1);

	if (s[s.size() - 1] == '.')
		s.erase(s.size() - 1, 1);
	return atof(s.c_str());
}

template<typename T, int max_size>
void drawOci(double Ysize, double Xsize, Text  verticalNom[22], Text horizontalNom[22], Font arial, int n) {
	int namb = 0, Xshag = 0, Yshag = Ysize;
	for (double i = roundDouble(-10 / pow(2, n) * 100) / 100.0; i <= roundDouble(10 / pow(2, n) * 100) / 100.0;
		i += roundDouble(1 / pow(2, n) * 100) / 100.0) {
		std::string s = std::to_string(i);
		int count = s.length() - 1;//s[count] == '.'
		while ((i != 0) && ((s[count] == '.') || (s[count] == '0' && s[count - 1] == '0') || (s[count] == '0' && s[count - 1] == '.') || (s[count] == '0' && s[abs(count - 2)] == '.') || (s[count] == '0' && s[abs(count - 3)] == '.'))) {
			s.pop_back();
			count -= 1;
		}

		std::cout << i << "  " << s << '\n';
		if (i != 0) {
			verticalNomber[namb].setFont(arial);
			verticalNomber[namb].setCharacterSize(20);
			verticalNomber[namb].setFillColor(Color::Black);
			verticalNomber[namb].setString(s);
			verticalNomber[namb].setPosition(Xshag - 5, Ysize / 2);
		}
		else {
			horizontNomber[namb].setFont(arial);
			horizontNomber[namb].setCharacterSize(20);
			horizontNomber[namb].setFillColor(Color::Black);
			horizontNomber[namb].setString("0");
			horizontNomber[namb].setPosition(Xsize / 4 + 5, Yshag);
			Yshag -= 50;
			Xshag += 50;
			namb++;
			continue;
		}
		Xshag += 50;

		horizontNomber[namb].setFont(arial);
		horizontNomber[namb].setCharacterSize(20);
		horizontNomber[namb].setFillColor(Color::Black);
		horizontNomber[namb].setString(s);
		horizontNomber[namb].setPosition(Xsize / 4 + 5, Yshag);
		Yshag -= 50;

		namb++;
	}
}