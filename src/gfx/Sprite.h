#pragma once

#include <SFML/Graphics.hpp>

class Window;

enum SPRITE_ID
{
	MISSING,
	MONKEY
};

class Sprite
{
public:
	static constexpr unsigned int SPRITE_SIZE{ 8 };		// 8x8 is the smallest size a sprite can be, and can scale up as multiple of 8

private:
	sf::Sprite sprite;

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

public:
	Sprite() {}
	Sprite(sf::Texture& t, const unsigned int id, const unsigned int w, const unsigned int h, const unsigned int scale, const int x, const int y);

	void init(sf::Texture& t, const unsigned int id, const unsigned int w, const unsigned int h, const unsigned int scale, const int x, const int y);

	void draw(Window& Window);

	void virtual update();	// generic update, runs every frame
	void updateProperties();	// only done after changing non pos members: updates things like scale, crop
	
	sf::Sprite& getSprite();
	const unsigned int getID() const;

	void updatePos();
	void setPos(const int x, const int y);
	const sf::Vector2i getPos() const;

	void setTexture(const sf::Texture& t);
	void setID(const unsigned int id);
};