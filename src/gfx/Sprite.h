#pragma once

#include <SFML/Graphics.hpp>

class Sprite
{
private:
	sf::Texture* texture;
	sf::Sprite sprite;
	int width;
	int height;
	int xPos;
	int yPos;

public:
	Sprite(int w, int h, int x, int y);
};