#include "Snake.h"

#include <iostream>

Snake::Snake()
{
	head.setSize(sf::Vector2f(50.0f, 50.0f));
	head.setFillColor(sf::Color::Color(0, 255, 0, 125));
	head.setPosition(sf::Vector2f(750.0f, 750.0f));
	prevHead = head;
	tempTail = prevHead;

	for (int i = 0; i < 3; i++) {
		tempTail.setPosition(tempTail.getPosition().x, tempTail.getPosition().y + 50.0f);
		tail.push_back(tempTail);
		prevTail.push_back(tempTail);
	}
	//tailPosition = std::vector<sf::Vector2f>(tail.size() - 1);
	std::cout << tail.size() << std::endl;
}

Snake::~Snake()
{
}

void Snake::move(float &time, float &timer, sf::Event &event) {
	std::cout << time << std::endl;
	float delay = 0.1;
	switch (event.type) {
	case sf::Event::KeyReleased:
		switch (event.key.code) {
		case sf::Keyboard::W:
			if (timer > delay) {
				timer = 0.0;
				prevHead = head;
				head.setPosition(head.getPosition().x, head.getPosition().y - 50.0f);
				for (int i = 0; i < tail.size(); i++) {
					if (i == 0) {
						tail[i] = prevHead;
						prevTail[i] = tail[i];
					}
					else {
						tail[i] = prevTail[i];
						prevTail[i] = tail[i - 1];
					}
				}
			}
			break;
		case sf::Keyboard::S:
			if (timer > delay) {
				timer = 0.0;
				prevHead = head;
				head.setPosition(head.getPosition().x, head.getPosition().y + 50.0f);
				for (int i = 0; i < tail.size(); i++) {
					if (i == 0) {
						tail[i] = prevHead;
						prevTail[i] = tail[i];
					}
					else {
						tail[i] = prevTail[i];
						prevTail[i] = tail[i - 1];
					}
				}
			}
			break;
		case sf::Keyboard::A:
			if (timer > delay) {
				timer = 0.0;
				prevHead = head;
				head.setPosition(head.getPosition().x - 50.0f, head.getPosition().y);
				for (int i = 0; i < tail.size(); i++) {
					if (i == 0) {
						tail[i] = prevHead;
						prevTail[i] = tail[i];
					}
					else {
						tail[i] = prevTail[i];
						prevTail[i] = tail[i - 1];
					}
				}
			}
			break;
		case sf::Keyboard::D:
			if (timer > delay) {
				timer = 0.0;
				prevHead = head;
				head.setPosition(head.getPosition().x + 50.0f, head.getPosition().y);
				for (int i = 0; i < tail.size(); i++) {
					if (i == 0) {
						tail[i] = prevHead;
						prevTail[i] = tail[i];
					}
					else {
						tail[i] = prevTail[i];
						prevTail[i] = tail[i - 1];
					}
				}
			}
			break;
		}
	}
}

void Snake::Draw(sf::RenderWindow &window) {
	window.draw(head);
	for (int i = 0; i < 3; i++) {
		window.draw(tail[i]);
	}
}