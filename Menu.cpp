#include "Menu.h"
#include <iostream>



Menu::Menu(sf::Vector2f &dimensions)
{
	this->dimensions = dimensions;
	if (!font.loadFromFile("font.ttf")) {
		std::cout << "File not found!" << std::endl;
	}
}


Menu::~Menu()
{
}

void Menu::menu() {

	menuOptions[0].setString("Snake");
	menuOptions[1].setString("Play");
	menuOptions[2].setString("Exit");

	menuOptions[0].setFont(font);
	menuOptions[0].setCharacterSize(300);
	menuOptions[0].setFillColor(sf::Color::Color(0, 255, 102));
	menuOptions[0].setPosition(sf::Vector2f(300.0f, 250.0f));

	int a = 400;
	for (int i = 1; i < 3; i++) {
		menuOptions[i].setFont(font);
		menuOptions[i].setCharacterSize(70);
		menuOptions[i].setFillColor(sf::Color::Color(0, 255, 102));
		menuOptions[i].setPosition(sf::Vector2f(550.0f, dimensions.y - a));
		a -= 100;
	}
	int b = 400;
	for (int i = 0; i < 2; i++) {
		menuPointer[i].setFont(font);
		menuPointer[i].setCharacterSize(70);
		menuPointer[i].setString(">");
		menuPointer[i].setFillColor(sf::Color::Black);
		menuPointer[i].setPosition(sf::Vector2f(550.0f, dimensions.y - b));
		b -= 100;
	}
	menuPointer[0].setFillColor(sf::Color::Color(0, 255, 102));
}

void Menu::setScore(int i) {
	score[0].setString(std::to_string(i));
	score[0].setFont(font);
	score[0].setCharacterSize(100);
	score[0].setFillColor(sf::Color::Color(0, 255, 102));
	score[0].setPosition(550.0f, 1125.0f);
}

void Menu::moveUp() {
	timer = 0.0;
	if (selectedOption - 1 >= 0) {
		selectedOption--;
		menuPointer[selectedOption].setFillColor(sf::Color::Color(0, 255, 102));
		menuPointer[selectedOption + 1].setFillColor(sf::Color::Black);
	}
}

void Menu::moveDown() {
	timer = 0.0;
	if (selectedOption + 1 >= 0 && selectedOption + 1 <= 1) {
		selectedOption++;
		menuPointer[selectedOption].setFillColor(sf::Color::Color(0, 255, 102));
		menuPointer[selectedOption - 1].setFillColor(sf::Color::White);
	}
}

void Menu::Draw(sf::RenderWindow &window) {
	for (int i = 0; i < 3; i++) {
		window.draw(menuOptions[i]);
	}
	for (int i = 0; i < 2; i++) {
		window.draw(menuPointer[i]);
	}
	
	timer += 1.0 / 60.0;

	if ((int)timer % 6 == 0) {
		menuPointer[selectedOption].setFillColor(sf::Color::Black);
	}
	else if ((int)timer % 9 == 0) {
		menuPointer[selectedOption].setFillColor(sf::Color::Color(0, 255, 102));
	}
}

void Menu::drawScore(sf::RenderWindow &window) {
	window.draw(score[0]);
}

void Menu::userInterface() {

}