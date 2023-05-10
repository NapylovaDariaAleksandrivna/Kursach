#define Task3

#ifdef Task2
#include"calculator.h"
#include <iostream>
using namespace std;
int main() {
	parser obj;
	cin >> obj;
	cout << obj;
	calculator text;
	
	text.toGive(obj.getOut());
	cout << text;
}
#endif // Task2

#ifdef Task3 //sfml
#include"calculator.h"
#include <iostream> 
#include<string>
#include "GraphicsNeed.h"

#include<Windows.h>
int main() {
	
	//**********
	srand(time(NULL));
	RenderWindow win(VideoMode::getDesktopMode(), "Graphics"/*, sf::Style::Fullscreen*/);//VideoMode::getDesktopMode() VideoMode(1000, 500)
	View view = win.getDefaultView();
	Vector2u winSize = win.getSize();
	double Xsize = winSize.x;
	double Ysize = winSize.y;
	double X = -10, Y = 10;

	//Gribs&rigth pole
	VertexArray verticalGrib(Lines, 50);
	VertexArray horizontalGrib(Lines, 50);
	RectangleShape poleRigth(Vector2f(Xsize, Ysize));
	GribPole(verticalGrib, horizontalGrib, poleRigth, Xsize, Ysize);
	
	//Zoom Buttons 
	Texture plusBotton;
	plusBotton.loadFromFile("materials/plus.png");
	Sprite buttonPlus;
	buttonPlus.setTexture(plusBotton);
	buttonPlus.setPosition(905, 955);
	Texture minusBotton;
	minusBotton.loadFromFile("materials/minus.png");
	Sprite buttonMinus;
	buttonMinus.setTexture(minusBotton);
	buttonMinus.setPosition(955,955);
	//Text
	Font arial;
	arial.loadFromFile("Century Gothic Regular.ttf");
	Text textY;
	textY.setFillColor(Color::White);
	textY.setFont(arial);
	std::string s = "y= ";
	textY.setString(s);//
	textY.setPosition(1000+100, 75);
	Text text;
	text.setFillColor(Color::White);
	text.setFont(arial);
	text.setPosition(1000 + 135, 75);
	std::string stringValue = "";
	text.setString(stringValue);
	Text tError;
	tError.setFillColor(Color::White);
	tError.setFont(arial);
	std::string error = "";
	tError.setString(error);//
	tError.setPosition(Xsize / 2 + 25, 125);

	//Create lines graphic

	VertexArray lineOne(Lines, 1000);
	VertexArray lineTwo(Lines, 1000);
	
	//*****************************
	//this made for thick line
	VertexArray lineThree(Lines, 1000);
	VertexArray lineFour(Lines, 1000);
	VertexArray lineFive(Lines, 1000);
	VertexArray lineSix(Lines, 1000);
	//*****************************
	
	while (win.isOpen()) {
		Vector2i mousePos = Mouse::getPosition(win);
		Event ev;
		while (win.pollEvent(ev)) {
			if (ev.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) {
				win.close();
			}
			
			if (ev.type == Event::TextEntered) {
				if (ev.text.unicode == 8 && stringValue!="") {
					stringValue.pop_back();
				}
				else if (ev.text.unicode < 128 && ev.text.unicode != 8 && ev.text.unicode!='\n' && ev.text.unicode != '\r') {
					stringValue += static_cast<char>(ev.text.unicode);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Return) ) {
				
				pressed(lineOne, lineTwo, lineThree, lineFour, lineFive, lineSix, stringValue, X, Y, error);
				
			}
			
			/*if (ev.type == Event::Resized)
			{
				win.setSize(Vector2u(Xsize, Ysize));
			}*/
			if (ev.type == Event::MouseButtonPressed) {
				if (ev.key.code == Mouse::Left) {
					
					if (buttonMinus.getGlobalBounds().contains(mousePos.x, mousePos.y )&& Y!=3) {
						X -= 1;
						Y += 1;
						std::cout << "-\n";
						pressed(lineOne, lineTwo, lineThree, lineFour, lineFive, lineSix, stringValue, X, Y, error);
					}
					else if (buttonPlus.getGlobalBounds().contains(mousePos.x, mousePos.y) && Y != 10) {
						X += 1;
						Y -= 1;
						std::cout << "+\n";
						pressed(lineOne, lineTwo, lineThree, lineFour, lineFive, lineSix, stringValue, X, Y, error);
					}

				}

			}
		}
		
		
		win.clear(Color(197, 208, 230));
		
		win.draw(verticalGrib);
		win.draw(horizontalGrib);
		

		win.draw(lineOne);
		win.draw(lineTwo);

		win.draw(lineThree);
		win.draw(lineFour);
		win.draw(lineFive);
		win.draw(lineSix);

		win.draw(buttonMinus);
		win.draw(buttonPlus);

		win.draw(poleRigth);

		text.setString(stringValue);
		win.draw(text);

		win.draw(textY);

		tError.setString(error);
		win.draw(tError);

		win.display();
	}	
}

#endif // Task3
#ifdef Task4
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;
int main() {
	double Ysize = 500;
	double Xsize = 1000;
	RenderWindow win(VideoMode(Xsize, Ysize), "Window",
		Style::Titlebar | Style::Close);
	RectangleShape poleRigth(Vector2f(Xsize, Ysize));

	while (win.isOpen()) {
		Event ev;

		while (win.pollEvent(ev)) {
			if (ev.type == Event::Closed) {
				win.close();
			}
			if (ev.type == Event::Resized)
			{
				// update the view to the new size of the win
				std::cout << win.getSize().x << ' ' << win.getSize().y << '\n';
				Vector2u windowSize = win.getSize();
				unsigned int windowWidth = windowSize.x;
				unsigned int windowHeight = windowSize.y;
				double koef = 1;
				if (windowHeight < 501 or windowWidth < 1001) {
					win.setSize(Vector2u(Xsize,Ysize));
					continue;
				}
				else if (Xsize != windowWidth && Ysize == windowHeight) {
					koef = windowWidth * 1.0 / Xsize * 1.0;
					Xsize = windowWidth;
					Ysize = koef * Ysize;
				}
				else {
					koef = windowHeight * 1.0 / Ysize * 1.0;
					Ysize = windowHeight;
					Xsize = koef * Xsize;
				}

				std::cout << win.getSize().x << ' ' << win.getSize().y << '\n';
				poleRigth.setPosition(Xsize/2,0)
				((Xsize * 1.0 / 2, 0));
				poleRigth.setFillColor(Color::Black);
				win.setSize(Vector2u(Xsize, Ysize));
			}
		}


		poleRigth.setPosition({ Ysize / 2,0 });
		win.clear(Color::Black);
		win.draw(poleRigth);
		win.display();
	}
}
#endif // Task4
#ifdef Task5 //sfml
#include"calculator.h"
#include <iostream> 
#include<SFML/Graphics.hpp>
#include<string>
#include<math.h>

using namespace sf;

int main() {
	srand(time(NULL));
	int Xsize = 2000;
	int Ysize = 1000;
	RenderWindow win(VideoMode(Xsize, Ysize), "SFML Window");

	VertexArray verticalGrib(Lines, 50);
	VertexArray horizontalGrib(Lines, 50);

	for (int i = 0, y = 0, x = 0; i < 50; i += 2, y += 50, x += 50)
	{
		verticalGrib[i].position = Vector2f(0, 50 + y);
		verticalGrib[i + 1].position = Vector2f(Xsize / 2, 50 + y);

		horizontalGrib[i].position = Vector2f(50 + x, 0);
		horizontalGrib[i + 1].position = Vector2f(50 + x, Ysize);
	}

	RectangleShape lineY(Vector2f(4, Ysize));
	lineY.setPosition(498, 0);
	lineY.setFillColor(Color::Black);

	RectangleShape lineX(Vector2f(Xsize / 2, 4));
	lineX.setPosition(0, 498);
	lineX.setFillColor(Color::Black);

	RectangleShape pole(Vector2f(Xsize / 2, Ysize));
	pole.setPosition(Xsize / 2, 0);
	pole.setFillColor(Color::Black);

	Font arial;
	arial.loadFromFile("Century Gothic Regular.ttf");
	Text textY;
	textY.setFillColor(Color::White);
	textY.setFont(arial);
	std::string s = "Math task: ";
	textY.setString(s);//
	textY.setPosition(Xsize / 2 + 25, 75);
	Text text;
	text.setFillColor(Color::White);
	text.setFont(arial);
	text.setPosition(Xsize / 2 + 200, 75);
	std::string stringValue = "";
	text.setString(stringValue);
	Text tError;
	tError.setFillColor(Color::White);
	tError.setFont(arial);
	std::string error = "";
	tError.setString(error);//
	tError.setPosition(Xsize / 2 + 25, 125);

	VertexArray lineOne(Lines, 2000);

	VertexArray pointGraficT1(Points, 2000);
	VertexArray pointGraficT2(Points, 2000);
	VertexArray pointGraficT3(Points, 2000);
	VertexArray pointGraficT4(Points, 2000);
	VertexArray pointGraficT5(Points, 2000);
	while (win.isOpen()) {//работает когда окно открыто 
		Event ev;//обработка событий
		while (win.pollEvent(ev)) {
			if (ev.type == Event::Closed) {
				win.close();
			}
			if (ev.type == Event::TextEntered) {
				if (ev.text.unicode == 8 && stringValue != "") {
					stringValue.pop_back();
				}
				else if (ev.text.unicode < 128 && ev.text.unicode != 8 && ev.text.unicode != '\n' && ev.text.unicode != '\r') {
					stringValue += static_cast<char>(ev.text.unicode);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Return)) {
				
				pointGraficT1.clear();
				pointGraficT2.clear();
				pointGraficT3.clear();
				pointGraficT4.clear();
				pointGraficT5.clear();

				VertexArray lineOne(Lines, 2000);
				VertexArray pointGrafic1(Points, 2000);
				VertexArray pointGrafic2(Points, 2000);
				VertexArray pointGrafic3(Points, 2000);
				VertexArray pointGrafic4(Points, 2000);
				VertexArray pointGrafic5(Points, 2000);
				parser obj;
				calculator text;
				obj.setIn(stringValue);
				std::cout << obj;
				text.toGive(obj.getOut());
				//std::cout << text;
				if (text.GetSize() == 0 || obj.getOut() == "Error") {
					error = "Error";
					pointGrafic1.clear();
					pointGrafic2.clear();
					pointGrafic3.clear();
					pointGrafic4.clear();
					pointGrafic5.clear();
					break;
				}
				int b = 0;
				for (int i = 0; i < text.GetSize() - 1; i++) {
					std::cout << "X: " << text.arrX[i] << " Y: " << text.arrY[i] << "*" << std::endl;
					pointGrafic1[i].position = Vector2f(text.arrX[i], text.arrY[i]);
					pointGrafic1[i].color = Color::Red;
					pointGrafic2[i].position = Vector2f(text.arrX[i]+1, text.arrY[i]);
					pointGrafic2[i].color = Color::Red;
					pointGrafic3[i].position = Vector2f(text.arrX[i]-1, text.arrY[i]);
					pointGrafic3[i].color = Color::Red;
					pointGrafic4[i].position = Vector2f(text.arrX[i],text.arrY[i] +1);
					pointGrafic4[i].color = Color::Red;
					pointGrafic5[i].position = Vector2f(text.arrX[i] , text.arrY[i]-1) ;
					pointGrafic5[i].color = Color::Red;
				}
				/*for (int i = 1; i < text.arrX.GetSize() - 2; i++) {

					std::cout << "I: " << i << " X: " << text.arrX[i] << " Y: " << text.arrY[i] << " ";
					std::cout << int(text.arrY[i]) / 100 << std::endl;
					lineTwo[i - 1].position = Vector2f(text.arrX[i], text.arrY[i]);
					if (abs(text.arrY[i] - text.arrY[i + 1]) > hz ||
						abs(text.arrY[i - 1] - text.arrY[i]) > hz) {
						lineTwo[i - 1].color = Color(255, 192, 203);
						std::cout << "**********\n";
					}
					else
						lineTwo[i - 1].color = Color::Red;
				}*/
				error = "";
				
				pointGraficT1 = pointGrafic1;
				pointGraficT2 = pointGrafic2;
				pointGraficT3 = pointGrafic3;
				pointGraficT4 = pointGrafic4;
				pointGraficT5 = pointGrafic5;
				
			}
		}
		win.clear(Color(255, 192, 203));

		win.draw(verticalGrib);
		win.draw(horizontalGrib);

		
		win.draw(lineY);
		win.draw(lineX);

		win.draw(pole);
		text.setString(stringValue);
		win.draw(text);

		win.draw(textY);

		tError.setString(error);
		win.draw(tError);

		win.draw(pointGraficT1);
		win.draw(pointGraficT2);
		win.draw(pointGraficT3);
		win.draw(pointGraficT4);
		win.draw(pointGraficT5);

		win.display();
	}
}
#endif // Task3