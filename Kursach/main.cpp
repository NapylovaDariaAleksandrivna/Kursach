#define Task3
#ifdef Task2
#include"calculator.h"
#include <iostream>
using namespace std;
int main() {
	double x1 = -20, x2 = 20, y1 = -20, y2 = 20, dep = 0.20;
	parser obj;
	cin >> obj;
	cout << obj;
	calculator g;
	MyVector arrX(100), arrY(100);
	g.toGive(obj.getOut(),arrY,arrX,x1,x2,y1,y2,dep);
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



	//������ ��������

	
	parser obj;
	std::cin >> obj;
	std::cout << obj;
	calculator g;
	MyVector arrX(1000), arrY(1000); 
	g.toGive(obj.getOut(), arrY, arrX);
	VertexArray pointGraficLeft(Points, arrX.GetSize());
	VertexArray lineL(Lines);
	for (int i = 0; i < arrX.GetSize(); i++) {
		int x = arrX[i];
		int y = arrY[i];
		std::cout << "X: " << x << " Y: " << y << std::endl;
		pointGraficLeft[i].position = Vector2f(x, y);
		pointGraficLeft[i].color = Color::Black;
		if (i != 0) {
			Vertex line[] =
			{
			 Vertex(Vector2f(arrX[i], arrY[i])),
			 Vertex(Vector2f(arrX[i - 1], arrY[i - 1]))
			};
		}
	}


	

	








	while (win.isOpen()) {//�������� ����� ���� ������� 
		Event ev;//��������� �������
		while (win.pollEvent(ev)) {
			if (ev.type == Event::Closed) {//���� ������������ �������� �������� ���� �� ��� ���� ���������(��� �� �������������� �������� � ��� �� ��������� �� ��������������)
				win.close();
			}
		}
		win.clear(Color(255, 192, 203));

		win.draw(verticalGrib);
		win.draw(horizontalGrib);
		win.draw(lineY);
		win.draw(lineX);
		win.draw(pointGraficLeft);
		win.draw(lineL);//
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


//���� ������?

