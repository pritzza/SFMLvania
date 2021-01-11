#pragma once

#include "../util/AABB.h"

class Window;

enum SPRITE_ID	// loadable Sprites
{
	MISSING,
	MONKEY,
	//MONKEY2	// MAKKE SURE THE ORDER OF THESE ENUMS CORRESPOND TO THE ORDER OF SPRITES IN THE SPRITESHEET FROM TOP TO BOTTOM
};

class Sprite
{
public:
	static constexpr unsigned int SPRITE_SIZE{ 8 };		// base dimensions for all sprites will be multiples of 8 and atleast 8x8 px

private:
	sf::Sprite sprite;

	unsigned int spriteID{ 0 };	// used for identifying sprite texture and cropping texture out of spritesheet

public:
	AABB bb;

private:
	void initSprite(sf::Texture& t);	// sets sprite's texture and calls setUp();

	void virtual updateCrop();	// set textureRect around sprite using spriteID and dimensions

	void updateScale();
	void updatePos();	// sets wrapper's sf::Sprite's position to wrappers x y position

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
	const sf::Vector2f getPos() const;		// returns sf::Vector2i of x y position

	void setID(const unsigned int id);
	const unsigned int getID() const;

	void draw(Window& Window, const bool drawRect);
	void draw(Window& Window);
};