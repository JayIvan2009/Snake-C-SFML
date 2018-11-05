#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Menu
{
public:
	Menu(sf::Vector2f &dimensions);
	~Menu();

	void menu();
	void moveUp();
	void moveDown();
	void Draw(sf::RenderWindow &window);
	void drawScore(sf::RenderWindow &window);

	void userInterface();
	void setScore(int i);
	
	int getOption() { return selectedOption; };

private:
	sf::Vector2f dimensions;
	sf::Text menuOptions[3];
	sf::Text menuPointer[2];
	sf::Text score[1];
	sf::Font font;

	int selectedOption = 0;
	float timer = 0.0;
};

