#include "Grid.h"
#include "Snake.h"

#include <iostream>

Grid::Grid(sf::Vector2f &dimensions)
	: dimensions(dimensions)
{
	double i = 0.005 * (this->dimensions.x / (this->dimensions.x * (this->dimensions.x / 1000)));
	gridCount = 400;

	grid = std::vector<sf::RectangleShape>(gridCount);

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
		size = grid[i].getSize();
		if (position.x == dimensions.x) {
			position.x = 0.0f;
			position.y += size.y;
		}
		grid[i].setPosition(position.x, position.y);
		grid[i].setOutlineThickness(-(dimensions.x * j));
		grid[i].setOutlineColor(sf::Color::Color(235, 235, 235));

		pos = grid[i].getPosition();
		position.x += size.x;
	}
}

void Grid::showGrid(sf::RenderWindow &window) {
	for (int i = 0; i < gridCount; i++) {
		window.draw(grid[i]);
	}
}