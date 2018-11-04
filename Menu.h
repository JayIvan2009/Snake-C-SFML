#pragma once
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

	void userInterface();
	
	int getOption() { return selectedOption; };

private:
	sf::Vector2f dimensions;
	sf::Text menuOptions[3];
	sf::Text menuPointer[2];
	sf::Font font;

	int power;
	int food;
	int water;
	int oxygen;
	int materials;

	int selectedOption = 0;
	float timer = 0.0;
};

