#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Grid.h"

class Snake
{
public:
	// snake Constructor
	Snake(sf::Vector2f &dimensions, Grid &grid);

	// draw function for the snake nodes
	void Draw(sf::RenderWindow &window);
	// move function for snake
	void move(float &time, float &timer, sf::Event &event);
	// follow function for snake
	void follow();
	// food function
	void foodSpawn();

	int getScore() { return score; };

private:
	int score = 0;
	// variable for the head node
	sf::RectangleShape head;
	// variable for the previous location of the head node
	sf::RectangleShape prevHead;
	// variable for food
	sf::RectangleShape food;
	// temp tail used to push back into tail and prevtail vector
	sf::RectangleShape tempTail;

	// vector for each tail nodes
	std::vector<sf::RectangleShape> tail;
	// vector for the previous locations of each tail nodes
	std::vector<sf::RectangleShape> prevTail;
	// vector for the borders
	std::vector<sf::RectangleShape> border;
};

