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

void GribPole(VertexArray &verticalGrib, VertexArray &horizontalGrib, RectangleShape &pole, float Xsize, float Ysize) {
	for (double i = 0, y = -2, x = 0; i < 43; i += 2, y += 50, x += 50)
	{
		horizontalGrib[i].position = Vector2f(0, Ysize / 20 + y-2);
		horizontalGrib[i + 1].position = Vector2f(Ysize , Ysize / 20 + y-2);

		verticalGrib[i].position = Vector2f(50 + x, 0);
		verticalGrib[i + 1].position = Vector2f(50 + x, Ysize);

		horizontalGrib[i].color = Color::Green;
		horizontalGrib[i + 1].color = Color::Green;
		if (i == 18) {
			horizontalGrib[i].color = Color::Black;
			verticalGrib[i].color = Color::Black;
			horizontalGrib[i+1].color = Color::Black;
			verticalGrib[i+1].color = Color::Black;
			
			
		}
	}

	pole.setPosition(Vector2f(1000, 0));
	pole.setFillColor(Color::Black);
	pole.setSize(Vector2f(Xsize, Ysize));
}

void pressed(VertexArray& lineOne, VertexArray& lineTwo, 
			VertexArray& lineThree, VertexArray& lineFour,
			VertexArray& lineFive, VertexArray& lineSix,
	std::string stringValue, double X, double Y, std::string& error) {
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
	calculator objC(obj, X, Y);
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