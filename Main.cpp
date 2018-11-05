#include <SFML/Graphics.hpp>

#include <iostream>
#include <vld.h>

#include "Menu.h"
#include "Grid.h"
#include "Snake.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1100, 1300), "Space Survival");
	sf::Vector2f dimensions(1000.0f, 1000.0f);
	sf::Clock clock;
	Menu menu(dimensions);
	Grid grid(dimensions);
	Snake snake(dimensions, grid);
	grid.setGrid();

	menu.menu();
	bool exitMenu = false;
	bool loadGrid = false;

	float time;
	float timer = 0;

	while (window.isOpen()) {
		time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			switch (event.type) {
			case sf::Event::KeyReleased:
					switch (event.key.code) {
					case sf::Keyboard::Enter:
						switch (menu.getOption()) {
							case 0:
								std::cout << "Play is pressed" << std::endl;
								exitMenu = true;
								loadGrid = true;
								break;
							case 1:
								std::cout << "Load is pressed" << std::endl;
								break;
							case 2:
								std::cout << "Settings is pressed" << std::endl;
								break;
							case 3:
								std::cout << "Exit is pressed" << std::endl;
								break;
						}
						break;
					case sf::Keyboard::W:
						menu.moveUp();
						break;
					case sf::Keyboard::S:
						menu.moveDown();
						break;
					}
			}
		}

		window.clear(sf::Color::Color(255, 255, 255));
		if (!exitMenu) {
			menu.Draw(window);
		}
		else {
			menu.setScore(snake.getScore());
			menu.drawScore(window);
			grid.showGrid(window);
			snake.Draw(window);
			snake.move(time, timer, event);
		}
		window.display();
	}
}
