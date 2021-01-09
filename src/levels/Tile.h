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

class Tile
{
	static constexpr unsigned int LENGTH{ 1 };	// all tiles gonna be 1x1
	static constexpr unsigned int SCALE{ 2 };	// all tiles gonna be 8pxx8px

private:
	Sprite sprite;

	TILE_SOLID solid;
	TILE_SPECIAL special;

public:
	void init(ResourceManager<TEXTURES, sf::Texture>& tm, const int lvlw, const int pos, const unsigned int sprite, const TILE_SOLID solid, const TILE_SPECIAL special);

	void initRect(const unsigned int stroke, const unsigned int opacity);

	void update(const unsigned int sprite, const TILE_SOLID solid, const TILE_SPECIAL special);	// update properties

	void draw(Window& window, const bool drawRect);
	void draw(Window& window);

	const unsigned int getSpriteID() const;
	const TILE_SOLID getSolid() const;
	const TILE_SPECIAL getSpecial() const;

	const unsigned int getLength() const;
	const unsigned int getScale() const;

	void setPosition(const int x, const int y);

private:
	void initSprite(ResourceManager<TEXTURES, sf::Texture>& tm, const unsigned int sprite, const int lvlw, const int pos);

	void updateSprite();
	void updateRect();
	
};