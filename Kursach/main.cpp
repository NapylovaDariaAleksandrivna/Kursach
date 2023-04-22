#define Task3
#ifdef Task2
#include"calculator.h"
#include <iostream>
using namespace std;
int main() {
	parser obj;
	cin >> obj;
	cout << obj;
	calculator g;
	MyVector arrX(100), arrY(100);
	g.toGive(obj.getOut(),arrY,arrX,-4,4,0.01);
	cout << "x " << arrX << '\n';
	cout << "y " << arrY;
}
#endif // Task2

#ifdef Task3 //sfml
#include"calculator.h"
#include <iostream> 
#include<SFML/Graphics.hpp>
#include<iostream>
#include<math.h>

using namespace sf;

int main() {
	srand(time(NULL));
	int Xsize = 1000;
	int Ysize = 1000;
	RenderWindow win(VideoMode(Xsize, Ysize), "SFML Window");

	VertexArray verticalGrib(Lines, 50);
	VertexArray horizontalGrib(Lines, 50);

	for (int i = 0, y = 0, x = 0; i < 50; i += 2, y += 50, x += 50)
	{
		verticalGrib[i].position = Vector2f(0, 50 + y);
		verticalGrib[i + 1].position = Vector2f(1000, 50 + y);

		horizontalGrib[i].position = Vector2f(50 + x, 0);
		horizontalGrib[i + 1].position = Vector2f(50 + x, 1000);
	}

	RectangleShape lineY(Vector2f(4, 1000));
	lineY.setPosition(498, 0);
	lineY.setFillColor(Color::Black);

	RectangleShape lineX(Vector2f(1000, 4));
	lineX.setPosition(0, 498);
	lineX.setFillColor(Color::Black);





	parser obj;
	std::cin >> obj;
	std::cout << obj;
	calculator g;
	MyVector arrX(1000), arrY(1000);
	g.toGive(obj.getOut(), arrY, arrX);
	//График параболы
	//VertexArray pointGraficLeft(Points);
	VertexArray myLines1(Lines, arrX.GetSize());
	VertexArray myLines2(Lines, arrX.GetSize());
	for (int i = 0; i < arrX.GetSize(); i++) {
		int x = arrX[i];
		int y = arrY[i];
		std::cout << "X: " << x << " Y: " << y << std::endl;
		myLines1[i].position = Vector2f(x, y);
		myLines1[i].color = Color::Black;
		if (i <= arrX.GetSize() - 2) {//Только при минус 2!!!!
			x = arrX[i + 1];
			y = arrY[i + 1];
			std::cout << "X: " << x << " Y: " << y << std::endl;
			myLines2[i].position = Vector2f(x, y);
			myLines2[i].color = Color::Black;
		}
	}
	

	while (win.isOpen()) {//работает когда окно открыто 
		Event ev;//обработка событий
		while (win.pollEvent(ev)) {
			if (ev.type == Event::Closed) {//если пользователь запросил закрытие окна мы его сами закрываем(это не автоматическое действие и оно по умолчанию не обрабатывается)
				win.close();
			}
		}
		win.clear(Color(255, 192, 203));

		win.draw(verticalGrib);
		win.draw(horizontalGrib);
		win.draw(lineY);
		win.draw(lineX);
		win.draw(myLines1);
		win.draw(myLines2);
		//win.draw(pointGraficLeft);
		//win.draw(pointGraficRight);
		//win.draw(pointGraficS);
		//win.draw(pointGraficSR);
		//win.draw(lineGrafics);
		//win.draw(lines);
		//win.draw(lines2);
		win.display();
	}
}
#endif // Task3


//Куча знаков?

