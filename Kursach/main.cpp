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
	MyVector arrX(100), arrY(100);
	text.toGive(obj.getOut(),arrY,arrX,-4,4,0.01);
	cout << "x " << arrX << '\n';
	cout << "y " << arrY;
}
#endif // Task2

#ifdef Task3 //sfml
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
		verticalGrib[i + 1].position = Vector2f(Xsize/2, 50 + y);

		horizontalGrib[i].position = Vector2f(50 + x, 0);
		horizontalGrib[i + 1].position = Vector2f(50 + x, Ysize);
	}

	RectangleShape lineY(Vector2f(4, Ysize));
	lineY.setPosition(498, 0);
	lineY.setFillColor(Color::Black);

	RectangleShape lineX(Vector2f(Xsize/2, 4));
	lineX.setPosition(0, 498);
	lineX.setFillColor(Color::Black);

	RectangleShape pole(Vector2f(Xsize/2, Ysize));
	pole.setPosition(Xsize/2, 0);
	pole.setFillColor(Color::Black);
	
	Font arial;
	arial.loadFromFile("Century Gothic Regular.ttf");
	Text t;
	t.setFillColor(Color::White);
	t.setFont(arial);
	std::string s = "Math task: ";
	t.setString(s);//
	t.setPosition(Xsize/2+25, 75);
	Text text;
	text.setFillColor(Color::White);
	text.setFont(arial);
	text.setPosition(Xsize/2+200, 75);
	std::string k = "";
	text.setString(k);

	VertexArray myLines1(Lines, 1000);
	VertexArray myLines2(Lines, 1000);
	
	bool flag = true;
	while (win.isOpen()) {//работает когда окно открыто 
		Event ev;//обработка событий
		while (win.pollEvent(ev)) {
			if (ev.type == Event::Closed) {
				win.close();
			}
			if (ev.type == Event::TextEntered) {
				if (ev.text.unicode == 8 and k!="") {
					k.pop_back();
				}
				else if (ev.text.unicode < 128 and ev.text.unicode != 8) {
					k += static_cast<char>(ev.text.unicode);
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::Return) ) {
				parser obj;
				calculator object;
				MyVector arrX(1000), arrY(1000);
				std::cout << k << std::endl;
				obj.setIn(k);
				std::cout << obj;
				object.toGive(obj.getOut(), arrY, arrX);
				for (int i = 0; i < arrX.GetSize()-1; i++) {
					std::cout << "X: " << arrX[i] << " Y: " << arrY[i] << "*" << std::endl;
					myLines1[i].position = Vector2f(arrX[i], arrY[i]);
					myLines1[i].color = Color::Black;
				}
				for (int i = 1; i < arrX.GetSize(); i++) {
					
					std::cout << "X: " << arrX[i] << " Y: " << arrY[i] << std::endl;
					myLines2[i-1].position = Vector2f(arrX[i], arrY[i]);
					myLines2[i-1].color = Color::Black;
				}
				arrX.Clean();
				arrY.Clean();
				flag = false;
			}
		}
		win.clear(Color(255, 192, 203));

		win.draw(verticalGrib);
		win.draw(horizontalGrib);
		win.draw(lineY);
		win.draw(lineX);
		
		win.draw(pole);
		text.setString(k);
		win.draw(text);
		win.draw(t);
		win.draw(myLines1);
		win.draw(myLines2);
		win.display();
	}
}
#endif // Task3
#ifdef Task4
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main() {
	RenderWindow window(VideoMode(800, 600), "Window",
		Style::Titlebar | Style::Close);
	Font arial;
	arial.loadFromFile("Century Gothic Regular.ttf");
	Text t;
	t.setFillColor(Color::White);
	t.setFont(arial);
	std::string s = "Math task: ";
	t.setString(s);
	Text g;
	g.setFillColor(Color::White);
	g.setFont(arial);
	g.setPosition(200, 0);
	std::string k = "";
	g.setString(k);

	while (window.isOpen()) {
		Event event;

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type == Event::TextEntered) {
				if (event.text.unicode == 13) {
					std::cout << k;
				}
				else if (event.text.unicode == 8) {
					k.pop_back();
				}
				else if (event.text.unicode < 128) {
					k += static_cast<char>(event.text.unicode);
				}
				else {

				}
			}
		}

		g.setString(k);
		window.clear(Color::Black);
		window.draw(g);
		window.draw(t);
		window.display();
	}
}
#endif // Task4


//Куча знаков?
