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
	
	std::vector<sf::RectangleShape> getBorder() { return border; };
	sf::RectangleShape getGrid(int i) { return grid[i]; };

private:
	const int gridCount = 400;
	const int borderCount = 88;
	bool found = false;

	sf::Vector2f size;
	sf::RenderWindow window;
	sf::Vector2f position = sf::Vector2f(50.0f, 50.0f);
	sf::Vector2f dimensions;
	std::vector<sf::RectangleShape> grid = std::vector<sf::RectangleShape>(gridCount);
	std::vector<sf::RectangleShape> border = std::vector<sf::RectangleShape>(borderCount);
};

