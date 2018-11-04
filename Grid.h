#pragma once
#include <SFML/Graphics.hpp>
#include <vector>


class Grid
{
public:
	Grid(sf::Vector2f &dimensions);
	Grid() { ; };
	~Grid();

	void game();
	void setGrid();
	void showGrid(sf::RenderWindow &window);

private:
	int gridCount;
	bool found = false;

	sf::Vector2f size;
	sf::RenderWindow window;
	sf::Vector2f position;
	sf::Vector2f dimensions;
	std::vector<sf::RectangleShape> grid;
};

