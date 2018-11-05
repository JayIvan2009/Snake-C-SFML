#include "Grid.h"
#include "Snake.h"

#include <iostream>

Grid::Grid(sf::Vector2f &dimensions)
{
	this->dimensions.x = dimensions.x + 50.0f;
	this->dimensions.y = dimensions.y + 50.0f;
	double i = 0.005 * (this->dimensions.x / (this->dimensions.x * (this->dimensions.x / 1000)));

	size.x = 50.0f;
	size.y = 50.0f;
}

Grid::~Grid()
{
}

void Grid::game() {

}


void Grid::setGrid() {
	double j = 0.0025 * (this->dimensions.x / (this->dimensions.x * (this->dimensions.x / 1000)));
	sf::Vector2f pos;

	for (int i = 0; i < gridCount; i++) {
		grid[i].setSize(size);
		if (position.x == dimensions.x) {
			position.x = 50.0f;
			position.y += 50.0f;
		}
		grid[i].setPosition(position.x, position.y);
		grid[i].setOutlineThickness(-(dimensions.x * j));
		grid[i].setOutlineColor(sf::Color::Color(235, 235, 235));

		pos = grid[i].getPosition();
		position.x += 50.0f;
	}

	position.x = 0.0f;
	position.y = 0.0f;
	for (int i = 0; i < 24; i++) {
		border[i].setSize(size);
		border[i].setPosition(position.x, position.y);
		border[i].setFillColor(sf::Color::Color(200, 200, 200));
		position.x += 50.0f;
	}

	position.x = 0.0f;
	position.y = 50.0f;
	for (int i = 24; i < 65; i++) {
		if (position.x > 1050.0f) {
			position.x = 0.0f;
			position.y += 50.0f;
		}
		border[i].setSize(size);
		border[i].setPosition(position.x, position.y);
		border[i].setFillColor(sf::Color::Color(200, 200, 200));
		position.x += 1050.0f;
	}

	position.x = 0.0f;
	for (int i = 65; i < 88; i++) {
		border[i].setSize(size);
		border[i].setPosition(position.x, position.y);
		border[i].setFillColor(sf::Color::Color(200, 200, 200));
		position.x += 50.0f;
	}
}

void Grid::showGrid(sf::RenderWindow &window) {
	for (int i = 0; i < gridCount; i++) {
		window.draw(grid[i]);
	}
	for (int i = 0; i < borderCount; i++) {
		window.draw(border[i]);
	}
}