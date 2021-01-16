#pragma once

#include "../gfx/Sprite.h"

class Window;

template <class Key, class Resource>
class ResourceManager;

// resource manager
enum class TEXTURES;

// tile data
enum class TILE_SOLID;
enum class TILE_SPECIAL;

enum class BORDER_COLOR;

class Tile
{
public:
	static constexpr unsigned int LENGTH{ Sprite::SPRITE_SIZE };	// tiles are going to be LENGTHxLENGTH units in dimension from spriteSheet
	static constexpr unsigned int SCALE{ 2 };

private:
	Sprite sprite;

	TILE_SOLID solid;		// collision data
	TILE_SPECIAL special;	// will determine special properties of tile, such as an enemy spawner, trigger point, or health item container

private:
	void initSprite(ResourceManager<TEXTURES, sf::Texture>& tm, const int lvlw, const int pos, const unsigned int id);

	void updateSprite();	// updatesrectColor() and setsUp() sprite
	void updateRectColor();	// assigns color to s.boundingBox corresponding to solid

public:
	// iniialize spolid and special, then calls initSprite();
	void init(ResourceManager<TEXTURES, sf::Texture>& tm, const int lvlw, const int pos, const unsigned int sprite, const TILE_SOLID solid, const TILE_SPECIAL special);

	// assignes new tile data and updates sprite (calls updateRectColor and s.setUp())
	void setTile(const unsigned int sprite, const TILE_SOLID solid, const TILE_SPECIAL special);

	const AABB& getAABB() const;

	const unsigned int getSpriteID() const;
	const TILE_SOLID getSolid() const;
	const TILE_SPECIAL getSpecial() const;

	const unsigned int getSize() const;	// returns size of tile in pixels

	void setOutlineThickness(const unsigned int t);
	void setOutlineColor(const BORDER_COLOR& c);

	void setPosition(const int x, const int y);
	const sf::Vector2f getPosition() const;

	void draw(Window& window, const bool drawRect);	// pass in value for whether you want to draw bounding boxes
	void draw(Window& window);
	
};