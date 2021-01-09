#pragma once

#include <SFML/Graphics.hpp>

class Window;

enum SPRITE_ID
{
	MISSING,
	MONKEY
};

enum class BORDER_COLOR
{
	RED,
	WHITE,
	GREEN,
};

class Sprite
{
public:
	static constexpr unsigned int SPRITE_SIZE{ 8 };		// 8x8 is the smallest size a sprite can be, and can scale up as multiple of 8

private:
	sf::Sprite sprite;
	sf::RectangleShape boundingBox;

	unsigned int spriteID{ 0 };

	unsigned int width{ 1 };
	unsigned int height{ 1 };
	unsigned int scale{ 1 };

public:
	int xPos{ 0 };
	int yPos{ 0 };

private:
	void virtual updateCrop();
	void updateScale();
	void updatePos();	// sets wrapper's sf::Sprite's position to wrappers x y position

public:
	Sprite() {}
	Sprite(sf::Texture& t, const unsigned int id, const unsigned int w, const unsigned int h, const unsigned int scale, const int x, const int y);
	void init(sf::Texture& t, const unsigned int id, const unsigned int w, const unsigned int h, const unsigned int scale, const int x, const int y);

	void initRect(const unsigned int stroke, const unsigned int opacity);

	void virtual update();	// generic update, runs every frame
	void updateProperties();	// only done after changing non pos members: updates things like scale, crop
	
	void updateBoundingBoxColor(const sf::Color c);
	void updateBoundingBoxColor(const BORDER_COLOR c);

	// wrapper getters & setters
	sf::Sprite& getSprite();

	void setTexture(const sf::Texture& t);

	void setPos(const int x, const int y);	// changes wrappers x y position
	const sf::Vector2i getPos() const;		// returns sf::Vector2i of x y position

	void setID(const unsigned int id);
	const unsigned int getID() const;
	
	void draw(Window& Window, const bool drawRect);
	void draw(Window& Window);
};