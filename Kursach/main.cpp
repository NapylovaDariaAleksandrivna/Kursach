#define Task3


#ifdef Task3 
#include"calculator.h"
#include <iostream> 
#include<string>
#include "GraphicsNeed.h"

int main() {
	srand(time(NULL));
	double sizeX = 2000;
	double sizeY = 1000;
	double copyX, copyY;
	double koef = 1;
	//************************
	RenderWindow win(VideoMode(sizeX, sizeY), "Graphics");
	//Gribs&rigth pole
	VertexArray verticalGrib(Lines, 50);
	VertexArray horizontalGrib(Lines, 50);
	RectangleShape lineY(Vector2f(4, sizeY));
	RectangleShape lineX(Vector2f(sizeX/2, 4));
	RectangleShape poleRigth(Vector2f(sizeX/2, sizeY));
	GribPole(verticalGrib, horizontalGrib, lineY, lineX, poleRigth, sizeX, sizeY);
	//Zoom Buttons 
	Texture plusBotton;
	plusBotton.loadFromFile("materials/plus.png");
	Sprite buttonPlus;
	buttonPlus.setTexture(plusBotton);
	buttonPlus.setPosition(955, 905);

	Texture minusBotton;
	minusBotton.loadFromFile("materials/minus.png");
	Sprite buttonMinus;
	buttonMinus.setTexture(minusBotton);
	buttonMinus.setPosition(955, 955);

	//function buttons
	Texture button1;
	button1.loadFromFile("materials/x^2.png");
	Sprite buttonOne;
	buttonOne.setTexture(button1);
	buttonOne.setPosition(1120, 350);

	Texture button2;
	button2.loadFromFile("materials/1x.png");
	Sprite buttonTwo;
	buttonTwo.setTexture(button2);
	buttonTwo.setPosition(1270, 350);

	Texture button3;
	button3.loadFromFile("materials/2x.png");
	Sprite buttonThree;
	buttonThree.setTexture(button3);
	buttonThree.setPosition(1420, 350);

	Texture button4;
	button4.loadFromFile("materials/lg.png");
	Sprite buttonFour;
	buttonFour.setTexture(button4);
	buttonFour.setPosition(1570, 350);

	Texture button5;
	button5.loadFromFile("materials/log2.png");
	Sprite buttonFive;
	buttonFive.setTexture(button5);
	buttonFive.setPosition(1720, 350);

	Texture button6;
	button6.loadFromFile("materials/sin.png");
	Sprite buttonSix;
	buttonSix.setTexture(button6);
	buttonSix.setPosition(1120, 520);

	Texture button7;
	button7.loadFromFile("materials/cos.png");
	Sprite buttonSeven;
	buttonSeven.setTexture(button7);
	buttonSeven.setPosition(1270, 520);

	Texture button8;
	button8.loadFromFile("materials/tg.png");
	Sprite buttonEight;
	buttonEight.setTexture(button8);
	buttonEight.setPosition(1420, 520);

	Texture button9;
	button9.loadFromFile("materials/ctg.png");
	Sprite buttonNine;
	buttonNine.setTexture(button9);
	buttonNine.setPosition(1570, 520);

	Texture button10;
	button10.loadFromFile("materials/ln.png");
	Sprite buttonTen;
	buttonTen.setTexture(button10);
	buttonTen.setPosition(1720, 520);
	
	//Text
	Font arial;
	int sizeText = 64;
	arial.loadFromFile("Century Gothic Regular.ttf");
	Text textY;
	textY.setFillColor(Color::White);
	textY.setFont(arial);
	std::string s = "y= ";
	textY.setString(s);//
	textY.setPosition(sizeX/2+165, 75);
	textY.setCharacterSize(sizeText);
	Text text;
	text.setFillColor(Color::White);
	text.setFont(arial);
	text.setPosition(sizeX/2+240, 75);
	std::string stringValue = "";
	text.setString(stringValue);
	text.setCharacterSize(sizeText);
	Text tError;
	tError.setFillColor(Color::White);
	tError.setFont(arial);
	std::string error = "";
	tError.setString(error);//
	tError.setPosition(sizeX / 2 + 165, 150);
	tError.setCharacterSize(sizeText);

	//Create lines graphic

	VertexArray lineOne(Lines, 1000);
	VertexArray lineTwo(Lines, 1000);
	
	//*****************************
	//this made for thick line
	VertexArray lineThree(Lines, 1000);
	VertexArray lineFour(Lines, 1000);
	VertexArray lineFive(Lines, 1000);
	VertexArray lineSix(Lines, 1000);
	VertexArray lineSeven(Lines, 1000);
	VertexArray lineEight(Lines, 1000);
	VertexArray lineNine(Lines, 1000);
	VertexArray lineTen(Lines, 1000);
	//*****************************

	int n = 0;
	float want_fps = 50;
	Clock loop_timer;
	//Osi
	Text verticalNomber[22];
	Text horizontNomber[22];
	//drawOci(sizeY, sizeX, verticalNomber, horizontNomber, arial, n);
	int namb = 0, Xshag = 0, Yshag = sizeY;
	for (double i = roundDouble(-10 / pow(2, n) * 100) / 100.0; i <= roundDouble(10 / pow(2, n) * 100) / 100.0;
		i += roundDouble(1 / pow(2, n) * 100) / 100.0) {
		std::string s = std::to_string(i);
		int count = s.length() - 1;//s[count] == '.'
		while ((i != 0) && ((s[count] == '.') || (s[count] == '0' && s[count - 1] == '0') || (s[count] == '0' && s[count - 1] == '.') || (s[count] == '0' && s[abs(count - 2)] == '.') || (s[count] == '0' && s[abs(count - 3)] == '.'))) {
			s.pop_back();
			count -= 1;
		}

		
		if (i != 0) {
			verticalNomber[namb].setFont(arial);
			verticalNomber[namb].setCharacterSize(20);
			verticalNomber[namb].setFillColor(Color::Black);
			verticalNomber[namb].setString(s);
			verticalNomber[namb].setPosition(Xshag - 5, sizeY / 2);
		}
		else {
			horizontNomber[namb].setFont(arial);
			horizontNomber[namb].setCharacterSize(20);
			horizontNomber[namb].setFillColor(Color::Black);
			horizontNomber[namb].setString("0");
			horizontNomber[namb].setPosition(sizeX / 4 + 5, Yshag);
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
		horizontNomber[namb].setPosition(sizeX / 4 + 5, Yshag);
		Yshag -= 50;

		namb++;
	}
	

	while (win.isOpen()) {
		clock_t times;
		times = clock();
		Event ev;
		while (win.pollEvent(ev)) {
			if (ev.type == Event::Closed) {
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
				
				isPressed(lineOne, lineTwo, stringValue, error, sizeY, n, 0,0);
				isPressed(lineThree, lineFour, stringValue, error, sizeY, n, 1, 0);
				isPressed(lineFive, lineSix, stringValue, error, sizeY, n, -1, 0);
				isPressed(lineSeven, lineEight, stringValue, error, sizeY, n, 0, 1);
				isPressed(lineNine, lineTen, stringValue, error, sizeY, n, 0,-1);
			}
			if (ev.type == Event::MouseButtonPressed) {
				if (ev.key.code == Mouse::Left) {
					Vector2f mousePos = win.mapPixelToCoords(Mouse::getPosition(win));
					if (buttonMinus.getGlobalBounds().contains(mousePos.x, mousePos.y) && n > 0) {
						n -= 1;
						int namb = 0, Xshag = 0, Yshag = sizeY;
						for (double i = roundDouble(-10 / pow(2, n) * 100) / 100.0; i <= roundDouble(10 / pow(2, n) * 100) / 100.0;
							i += roundDouble(1 / pow(2, n) * 100) / 100.0) {
							std::string s = std::to_string(i);
							int count = s.length() - 1;//s[count] == '.'
							while ((i != 0) && ((s[count] == '.') || (s[count] == '0' && s[count - 1] == '0') || (s[count] == '0' && s[count - 1] == '.') || (s[count] == '0' && s[abs(count - 2)] == '.') || (s[count] == '0' && s[abs(count - 3)] == '.'))) {
								s.pop_back();
								count -= 1;
							}

							
							if (i != 0) {
								verticalNomber[namb].setFont(arial);
								verticalNomber[namb].setCharacterSize(20);
								verticalNomber[namb].setFillColor(Color::Black);
								verticalNomber[namb].setString(s);
								verticalNomber[namb].setPosition(Xshag - 5, sizeY / 2);
							}
							else {
								horizontNomber[namb].setFont(arial);
								horizontNomber[namb].setCharacterSize(20);
								horizontNomber[namb].setFillColor(Color::Black);
								horizontNomber[namb].setString("0");
								horizontNomber[namb].setPosition(sizeX / 4 + 5, Yshag);
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
							horizontNomber[namb].setPosition(sizeX / 4 + 5, Yshag);
							Yshag -= 50;

							namb++;
						}
						if (stringValue != "") {

							isPressed(lineOne, lineTwo, stringValue, error, sizeY, n, 0, 0);
							isPressed(lineThree, lineFour, stringValue, error, sizeY, n, 1, 0);
							isPressed(lineFive, lineSix, stringValue, error, sizeY, n, -1, 0);
							isPressed(lineSeven, lineEight, stringValue, error, sizeY, n, 0, 1);
							isPressed(lineNine, lineTen, stringValue, error, sizeY, n, 0,-1);
						}


					}
					else if (buttonPlus.getGlobalBounds().contains(mousePos.x, mousePos.y) && n < 2) {
						
						n += 1;
						int namb = 0, Xshag = 0, Yshag = sizeY;
						for (double i = roundDouble(-10 / pow(2, n) * 100) / 100.0; i <= roundDouble(10 / pow(2, n) * 100) / 100.0;
							i += roundDouble(1 / pow(2, n) * 100) / 100.0) {
							std::string s = std::to_string(i);
							int count = s.length() - 1;//s[count] == '.'
							while ((i != 0) && ((s[count] == '.') || (s[count] == '0' && s[count - 1] == '0') || (s[count] == '0' && s[count - 1] == '.') || (s[count] == '0' && s[abs(count - 2)] == '.') || (s[count] == '0' && s[abs(count - 3)] == '.'))) {
								s.pop_back();
								count -= 1;
							}

							
							if (i != 0) {
								verticalNomber[namb].setFont(arial);
								verticalNomber[namb].setCharacterSize(20);
								verticalNomber[namb].setFillColor(Color::Black);
								verticalNomber[namb].setString(s);
								verticalNomber[namb].setPosition(Xshag - 5, sizeY / 2);
							}
							else {
								horizontNomber[namb].setFont(arial);
								horizontNomber[namb].setCharacterSize(20);
								horizontNomber[namb].setFillColor(Color::Black);
								horizontNomber[namb].setString("0");
								horizontNomber[namb].setPosition(sizeX / 4 + 5, Yshag);
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
							horizontNomber[namb].setPosition(sizeX / 4 + 5, Yshag);
							Yshag -= 50;

							namb++;
						}
						if (stringValue != "") {

							isPressed(lineOne, lineTwo, stringValue, error, sizeY, n, 0, 0);
							isPressed(lineThree, lineFour, stringValue, error, sizeY, n, 1, 0);
							isPressed(lineFive, lineSix, stringValue, error, sizeY, n, -1, 0);
							isPressed(lineSeven, lineEight, stringValue, error, sizeY, n, 0, 1);
							isPressed(lineNine, lineTen, stringValue, error, sizeY, n, 0,-1);
						}
					}
					else if (buttonOne.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						stringValue = "x^2";
						if (stringValue != "") {

							isPressed(lineOne, lineTwo, stringValue, error, sizeY, n, 0, 0);
							isPressed(lineThree, lineFour, stringValue, error, sizeY, n, 1, 0);
							isPressed(lineFive, lineSix, stringValue, error, sizeY, n, -1, 0);
							isPressed(lineSeven, lineEight, stringValue, error, sizeY, n, 0, 1);
							isPressed(lineNine, lineTen, stringValue, error, sizeY, n, 0,-1);
						}
					}
					else if (buttonTwo.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						stringValue = "1/x";
						if (stringValue != "") {

							isPressed(lineOne, lineTwo, stringValue, error, sizeY, n, 0, 0);
							isPressed(lineThree, lineFour, stringValue, error, sizeY, n, 1, 0);
							isPressed(lineFive, lineSix, stringValue, error, sizeY, n, -1, 0);
							isPressed(lineSeven, lineEight, stringValue, error, sizeY, n, 0, 1);
							isPressed(lineNine, lineTen, stringValue, error, sizeY, n, 0,-1);
						}
					}
					else if (buttonThree.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						stringValue = "2^x";
						if (stringValue != "") {

							isPressed(lineOne, lineTwo, stringValue, error, sizeY, n, 0, 0);
							isPressed(lineThree, lineFour, stringValue, error, sizeY, n, 1, 0);
							isPressed(lineFive, lineSix, stringValue, error, sizeY, n, -1, 0);
							isPressed(lineSeven, lineEight, stringValue, error, sizeY, n, 0, 1);
							isPressed(lineNine, lineTen, stringValue, error, sizeY, n, 0,-1);
						}
					}
					else if (buttonFour.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						stringValue = "lgx";
						if (stringValue != "") {

							isPressed(lineOne, lineTwo, stringValue, error, sizeY, n, 0, 0);
							isPressed(lineThree, lineFour, stringValue, error, sizeY, n, 1, 0);
							isPressed(lineFive, lineSix, stringValue, error, sizeY, n, -1, 0);
							isPressed(lineSeven, lineEight, stringValue, error, sizeY, n, 0, 1);
							isPressed(lineNine, lineTen, stringValue, error, sizeY, n, 0,-1);
						}
					}
					else if (buttonFive.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						stringValue = "log2x";
						if (stringValue != "") {

							isPressed(lineOne, lineTwo, stringValue, error, sizeY, n, 0, 0);
							isPressed(lineThree, lineFour, stringValue, error, sizeY, n, 1, 0);
							isPressed(lineFive, lineSix, stringValue, error, sizeY, n, -1, 0);
							isPressed(lineSeven, lineEight, stringValue, error, sizeY, n, 0, 1);
							isPressed(lineNine, lineTen, stringValue, error, sizeY, n, 0,-1);
						}
					}
					else if (buttonSix.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						stringValue = "sinx";
						if (stringValue != "") {

							isPressed(lineOne, lineTwo, stringValue, error, sizeY, n, 0, 0);
							isPressed(lineThree, lineFour, stringValue, error, sizeY, n, 1, 0);
							isPressed(lineFive, lineSix, stringValue, error, sizeY, n, -1, 0);
							isPressed(lineSeven, lineEight, stringValue, error, sizeY, n, 0, 1);
							isPressed(lineNine, lineTen, stringValue, error, sizeY, n, 0,-1);
						}
					}
					else if (buttonSeven.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						stringValue = "cosx";
						if (stringValue != "") {

							isPressed(lineOne, lineTwo, stringValue, error, sizeY, n, 0, 0);
							isPressed(lineThree, lineFour, stringValue, error, sizeY, n, 1, 0);
							isPressed(lineFive, lineSix, stringValue, error, sizeY, n, -1, 0);
							isPressed(lineSeven, lineEight, stringValue, error, sizeY, n, 0, 1);
							isPressed(lineNine, lineTen, stringValue, error, sizeY, n, 0,-1);
						}
					}
					else if (buttonEight.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						stringValue = "tgx";
						if (stringValue != "") {

							isPressed(lineOne, lineTwo, stringValue, error, sizeY, n, 0, 0);
							isPressed(lineThree, lineFour, stringValue, error, sizeY, n, 1, 0);
							isPressed(lineFive, lineSix, stringValue, error, sizeY, n, -1, 0);
							isPressed(lineSeven, lineEight, stringValue, error, sizeY, n, 0, 1);
							isPressed(lineNine, lineTen, stringValue, error, sizeY, n, 0,-1);
						}
					}
					else if (buttonNine.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						stringValue = "ctgx";
						if (stringValue != "") {

							isPressed(lineOne, lineTwo, stringValue, error, sizeY, n, 0, 0);
							isPressed(lineThree, lineFour, stringValue, error, sizeY, n, 1, 0);
							isPressed(lineFive, lineSix, stringValue, error, sizeY, n, -1, 0);
							isPressed(lineSeven, lineEight, stringValue, error, sizeY, n, 0, 1);
							isPressed(lineNine, lineTen, stringValue, error, sizeY, n, 0,-1);
						}
					}
					else if (buttonTen.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
						stringValue = "lnx";
						if (stringValue != "") {

							isPressed(lineOne, lineTwo, stringValue, error, sizeY, n, 0, 0);
							isPressed(lineThree, lineFour, stringValue, error, sizeY, n, 1, 0);
							isPressed(lineFive, lineSix, stringValue, error, sizeY, n, -1, 0);
							isPressed(lineSeven, lineEight, stringValue, error, sizeY, n, 0, 1);
							isPressed(lineNine, lineTen, stringValue, error, sizeY, n, 0,-1);
						}
					}
					
				}
			}
			if (ev.type == Event::Resized)
			{
				copyX = sizeX * koef;
				copyY = sizeY * koef;
				Vector2u windowSize = win.getSize();
				if (windowSize.x < 600 or windowSize.y < 300) {
					win.setSize(Vector2u(copyX, copyY));
					continue;
				}
				else if (copyX != windowSize.x && copyY == windowSize.y) {
					koef = windowSize.x * 1.0 / sizeX * 1.0;
				}
				else if (copyX == windowSize.x && copyY != windowSize.y) {
					koef = windowSize.y * 1.0 / sizeY * 1.0;
				}
				else {
					koef = windowSize.y * 1.0 / sizeY * 1.0;
				}
				poleRigth.setSize(Vector2f(sizeX, sizeY));
				win.setSize(Vector2u(sizeX * koef, sizeY * koef));
				
			}
		}
		
		win.clear(Color(197, 208, 230));
		
		win.draw(verticalGrib);
		win.draw(horizontalGrib);

		win.draw(lineY);
		win.draw(lineX);
		

		win.draw(lineOne);
		win.draw(lineTwo);

		win.draw(lineThree);
		win.draw(lineFour);
		win.draw(lineEight);
		win.draw(lineFive); 
		win.draw(lineSix);
		win.draw(lineSeven);
		win.draw(lineNine);
		win.draw(lineTen);
		
		win.draw(poleRigth);

		text.setString(stringValue);
		win.draw(text);

		win.draw(textY);

		tError.setString(error);
		win.draw(tError);

		win.draw(buttonMinus);
		win.draw(buttonPlus);

		win.draw(buttonOne);
		win.draw(buttonTwo);
		win.draw(buttonThree);
		win.draw(buttonFour);
		win.draw(buttonFive);
		win.draw(buttonSix);
		win.draw(buttonSeven);
		win.draw(buttonEight);
		win.draw(buttonNine);
		win.draw(buttonTen);

		for (int i = 0; i < 22; i++) {
			win.draw(verticalNomber[i]);
			win.draw(horizontNomber[i]);
		}
		
		Int32 frame_duration = loop_timer.getElapsedTime().asMilliseconds();
		Int32 time_to_sleep = int(1000.f / want_fps) - frame_duration;
		if (time_to_sleep > 0) {
			sleep(milliseconds(time_to_sleep));
		}
		loop_timer.restart();
		if ((double)((double)(clock() - times) / CLOCKS_PER_SEC) > 0.022) {
			std::cout << (double)((double)(clock() - times) / CLOCKS_PER_SEC) << '\n';
		}
		win.display();
		
	}
}
#endif // Task3