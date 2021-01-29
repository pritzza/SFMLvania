#pragma once

#include <SFML/Graphics.hpp>

class Camera
{
private:
	sf::View view;

	int xPos{};
	int yPos{};

	const unsigned int WIN_H{};
	const unsigned int WIN_W{};

	float zoom{};

public:
	Camera(const unsigned int W_W, const unsigned int W_H);

	void move(const int x, const int y);	// relative
	void setPos(const int x, const int y);	// absolute

	const sf::Vector2i getPos() const;

	void setView();	// gets the camera pointed in the right place
	const sf::View& getView() const;
};