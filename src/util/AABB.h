#pragma once

#include <SFML/Graphics.hpp>

enum class BORDER_COLOR	// colors that can be given to the outline of bounding boxes
{
	RED,
	WHITE,
	GREEN,
};

class AABB
{
private:
	sf::RectangleShape rect;
	sf::Color color;

	unsigned int width{ 1 };
	unsigned int height{ 1 };

	unsigned int scale{ 1 };

	int xPos{};
	int yPos{};

private:
	void updateSize();
	void updatePos();	// sets rect position to wrappers x y position
	void updateColor();

public:
	AABB() {};
	AABB(const unsigned int w, const unsigned int h, const int x, const int y, const unsigned int s);

	void init(const unsigned int w, const unsigned int h, const int x, const int y, const unsigned int s);

	void setUp();

	void update();

	void setColor(const BORDER_COLOR c);
	void setOutlineThickness(const unsigned int t);

	// setters and getters
	const sf::RectangleShape& getRect() const;

	void setScale(const unsigned int s);
	const unsigned int getScale() const;

	void setSize(const unsigned int w, const unsigned int h);	// takes width and height
	const sf::Vector2f getSize() const;		// returns sf::Vector2i of width and height

	void setPos(const unsigned int x, const unsigned int y);
	const sf::Vector2f getPos() const;		// returns sf::Vector2i of x y position
};