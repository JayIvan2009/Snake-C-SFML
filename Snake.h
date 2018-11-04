#pragma once
#include "Grid.h"

class Snake
{
public:
	Snake();
	~Snake();

	void Draw(sf::RenderWindow &window);
	void move(float &time, float &timer, sf::Event &event);

private:
	sf::RectangleShape head;
	std::vector<sf::RectangleShape> tail;
	sf::Vector2f temp;
	sf::RectangleShape prevHead;
	sf::RectangleShape tempTail;
	std::vector<sf::RectangleShape> prevTail;
	//sf::Vector2f headPosition = sf::Vector2f(750.0f, 750.0f);
	//std::vector<sf::Vector2f> tailPosition;
	float j = 50.0f;
};

