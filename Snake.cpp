#include "Snake.h"

#include <iostream>

Snake::Snake(sf::Vector2f &dimensions, Grid &grid)
	: border(grid.getBorder())
{
	// sets srand
	srand(time(NULL));
	float randomX = 50 * (rand() % 20);
	float randomY = 50 * (rand() % 20);

	// sets the head note
	head.setSize(sf::Vector2f(50.0f, 50.0f));
	head.setFillColor(sf::Color::Color(0, 255, 0, 125));
	head.setPosition(dimensions.x / 2, dimensions.y / 2);

	// sets the head note
	food.setSize(sf::Vector2f(50.0f, 50.0f));
	food.setFillColor(sf::Color::Color(255, 0, 0, 125));
	food.setPosition(randomX, randomY);

	for (int i = 0; i < border.size() - 1; i++) {
		if (food.getPosition().x == border[i].getPosition().x && food.getPosition().y == border[i].getPosition().y) {
			float randomX = 50 + (50 * (rand() % 20));
			float randomY = 50 + (50 * (rand() % 20));
			food.setPosition(randomX, randomY);
			break;
		}
	}

	// sets prevHead and tempTail to head node
	prevHead = head;
	tempTail = prevHead;

	// pushes back tempTail to tail and prevTail vectors to initialize them
	for (int i = 0; i < 2; i++) {
		tail.push_back(tempTail);
		prevTail.push_back(tempTail);
	}
	std::cout << border.size() << std::endl;
	std::cout << tail.size() << std::endl;
}

void Snake::move(float &time, float &timer, sf::Event &event) {
	foodSpawn();
	float delay = 0.1;

	// switch even for keyboard input
	switch (event.type) {
	case sf::Event::KeyReleased:

		switch (event.key.code) {
		// if a user presses W
		case sf::Keyboard::W:
			// once the timer is >= the delay
			if (timer >= delay) {
				// resets timer
				timer = 0.0;
				// sets prevHead to head node
				prevHead = head;
				// moves head node upwards
				head.setPosition(head.getPosition().x, head.getPosition().y - 50.0f);
				// calls follow function
				follow();
			}
			break;

		// if a user presses S
		case sf::Keyboard::S:
			// once the timer is >= the delay
			if (timer >= delay) {
				// resets timer
				timer = 0.0;
				// sets prevHead to head node
				prevHead = head;
				// moves head node downwards
				head.setPosition(head.getPosition().x, head.getPosition().y + 50.0f);
				// calls follow function
				follow();
			}
			break;

		// if a user presses A
		case sf::Keyboard::A:
			// once the timer is >= the delay
			if (timer >= delay) {
				// resets timer
				timer = 0.0;
				// sets prevHead to head node
				prevHead = head;
				// moves head node to the left
				head.setPosition(head.getPosition().x - 50.0f, head.getPosition().y);
				// calls follow function
				follow();
			}
			break;

		// if a user presses D
		case sf::Keyboard::D:
			// once the timer is >= the delay
			if (timer >= delay) {
				// resets timer
				timer = 0.0;
				// sets prevHead to head node
				prevHead = head;
				// moves head node to the right
				head.setPosition(head.getPosition().x + 50.0f, head.getPosition().y);
				// calls follow function
				follow();
			}
			break;
		}
	}
}

void Snake::follow() {
	for (int i = 0; i < tail.size(); i++) {
		// gets the first element of the tail vector
		if (i == 0) {
			// sets first element of tail vector to prevHead
			tail[i] = prevHead;
			// sets first element of prevTail to the tail
			prevTail[i] = tail[i];
		}
		else {
			// sets tail[i] to the prevTail[i]
			tail[i] = prevTail[i];
			// sets prevtail[i] to the previous tail node
			prevTail[i] = tail[i - 1];
		}
	}
}

void Snake::foodSpawn() {
	if (head.getPosition() == food.getPosition()) {
		score++;

		tempTail = tail.back();
		tail.push_back(tempTail);
		prevTail.push_back(tempTail);

		// sets srand
		float randomX = 50 + (50 * (rand() % 20));
		float randomY = 50 + (50 * (rand() % 20));

		for (int i = 0; i < tail.size(); i++) {
			if (randomX == tail[i].getPosition().x && randomY == tail[i].getPosition().y) {
				float randomX = 50 + (50 * (rand() % 20));
				float randomY = 50 + (50 * (rand() % 20));
				food.setPosition(randomX, randomY);
				break;
			}
		}

		food.setPosition(randomX, randomY);
	}

	for (int i = 0; i < tail.size() - 1; i++) {
		if (food.getPosition().x == tail[i].getPosition().x && food.getPosition().y == tail[i].getPosition().y) {
			float randomX = 50 + (50 * (rand() % 20));
			float randomY = 50 + (50 * (rand() % 20));
			food.setPosition(randomX, randomY);
			break;
		}
	}

	for (int i = 0; i < border.size() - 1; i++) {
		if (food.getPosition().x == border[i].getPosition().x && food.getPosition().y == border[i].getPosition().y) {
			float randomX = 50 + (50 * (rand() % 20));
			float randomY = 50 + (50 * (rand() % 20));
			food.setPosition(randomX, randomY);
			break;
		}
	}
}

void Snake::Draw(sf::RenderWindow &window) {
	// draws the head node
	window.draw(head);
	// draws the food node
	window.draw(food);

	// for loop to draw tail nodes
	for (int i = 0; i < tail.size(); i++) {
		window.draw(tail[i]);
	}
}