#pragma once

#include <SFML/Graphics.hpp>

class Window;

enum SPRITE_ID	// loadable Sprites
{
	MISSING,
	MONKEY
};

enum class BORDER_COLOR	// colors that can be given to the outline of bounding boxes
{
	RED,
	WHITE,
	GREEN,
};

class Sprite
{
public:
	static constexpr unsigned int SPRITE_SIZE{ 8 };		// base dimensions for all sprites will be multiples of 8 and atleast 8x8 px

private:
	sf::Sprite sprite;

	sf::RectangleShape boundingBox;
	sf::Color boundingBoxColor;

	unsigned int spriteID{ 0 };	// used for identifying sprite texture and cropping texture out of spritesheet

	// dimensions of tiles
	unsigned int width{ 1 };
	unsigned int height{ 1 };
	unsigned int scale{ 1 };

public:
	int xPos{ 0 };
	int yPos{ 0 };

private:
	void initSprite(sf::Texture& t);	// sets sprite's texture and calls setUp();
	void initRect();	// sets up bounding box

	void virtual updateCrop();	// set textureRect around sprite using spriteID and dimensions

	void updateScale();
	void updatePos();	// sets wrapper's sf::Sprite's position to wrappers x y position
	void updateBoundingBoxColor();

	void setTexture(const sf::Texture& t);

public:
	Sprite() {}

	// initialized members and calls initSprite, initRect
	Sprite(sf::Texture& t, const unsigned int id, const unsigned int w, const unsigned int h, const unsigned int scale, const int x, const int y);
	void init(sf::Texture& t, const unsigned int id, const unsigned int w, const unsigned int h, const unsigned int scale, const int x, const int y);

	void virtual update();	// generic update, runs every frame, only calls updatePos();

	void setUp();	// only done after changing non position members: updates things like scale, crop (calls those functions)

	//////////////////// wrapper getters & setters ////////////////////
	sf::Sprite& getSprite();

	void setPos(const int x, const int y);	// changes wrappers x y position
	const sf::Vector2i getPos() const;		// returns sf::Vector2i of x y position

	void setBoundingBoxColor(const BORDER_COLOR c);
	void setBoundingBoxOutlineThickness(const unsigned int t);

	void setID(const unsigned int id);
	const unsigned int getID() const;
	
	void draw(Window& Window, const bool drawRect);
	void draw(Window& Window);
};