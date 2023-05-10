#pragma once
#include<SFML/Graphics.hpp>
#include "vector.h"
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

void GribPole(VertexArray &verticalGrib, VertexArray &horizontalGrib, RectangleShape &pole, float Ysize){
	for (int i = 0, y = 0, x = 0; i < 43; i += 2, y += Ysize/20, x += Ysize/20)
	{
		verticalGrib[i].position = Vector2f(0, Ysize/20 + y);
		verticalGrib[i + 1].position = Vector2f(Ysize , Ysize/20 + y);

		horizontalGrib[i].position = Vector2f(Ysize/20 + x, 0);
		horizontalGrib[i + 1].position = Vector2f(Ysize/20 + x, Ysize);
		if (i == 18) {
			verticalGrib[i].color = Color::Black;
			horizontalGrib[i].color = Color::Black;
			verticalGrib[i+1].color = Color::Black;
			horizontalGrib[i+1].color = Color::Black;
			i += 2;
			verticalGrib[i].position = Vector2f(0, Ysize/20 + y-1);
			verticalGrib[i + 1].position = Vector2f(Ysize , Ysize/20 + y-1);

			horizontalGrib[i].position = Vector2f(Ysize/20 + x+1, 0+1);
			horizontalGrib[i + 1].position = Vector2f(Ysize/20 + x+1, Ysize+1);

			verticalGrib[i].color = Color::Black;
			horizontalGrib[i].color = Color::Black;
			verticalGrib[i + 1].color = Color::Black;
			horizontalGrib[i + 1].color = Color::Black;
		}
	}

	pole.setPosition(Ysize, 0);
	pole.setFillColor(Color::Black);
}
void pressEnter
(VertexArray& lineOne, VertexArray& lineTwo, VertexArray& lineThree, VertexArray& lineFour, VertexArray& lineFive, VertexArray& lineSix, std::string stringValue, std::string error, double Ysize, double X, double Y) {
	lineOne.clear();
	lineTwo.clear();
	lineOne.resize(2000);
	lineTwo.resize(2000);
	//*****************************
	lineThree.clear();
	lineFour.clear();
	lineFive.clear();
	lineSix.clear();

	lineThree.resize(2000);
	lineFour.resize(2000);
	lineFive.resize(2000);
	lineSix.resize(2000);
	//*****************************

	parser obj(stringValue);
	calculator objC(obj,Ysize, X, Y);
	std::cout << obj;
	if (objC.GetSize() == 0 || obj.getOut() == "Error") {
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

	int const hz = 50;//It is necessary that the tangent does not have sticks
	draw(lineOne, lineTwo, hz, objC.arrX, objC.arrY);

	//*****************************
	draw(lineThree, lineFour, hz, objC.arrX += 1, objC.arrY);
	draw(lineFive, lineSix, hz, objC.arrX, objC.arrY += -1);
	//*****************************

	error = "";
}