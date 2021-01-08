#pragma once

#include "../gfx/Sprite.h"

class Window;

template <class Key, class Resource>
class ResourceManager;

enum class TEXTURES;

enum TILE_SPRITE_ID
{
	MISSING_TILE,
	AIR,
	BRICK,
	GROUND,
	PLATFORM,
};

enum class TILE_SOLID
{
	SOLID,
	NOT_SOLID,
	//PLATFORM,
	//STAIRS,
};

enum class TILE_SPECIAL
{
	NONE,
	//BAT_SPAWNER,
};

class Tile
{
	static constexpr unsigned int LENGTH{ 1 };	// all tiles gonna be 1x1
	static constexpr unsigned int SCALE{ 2 };	// all tiles gonna be 8pxx8px

private:
	Sprite sprite;

	unsigned int spriteID;	// check if this should be here
	TILE_SOLID solid;
	TILE_SPECIAL special;

public:
	void init(ResourceManager<TEXTURES, sf::Texture>& tm, const int lvlw, const int pos, const unsigned int sprite, const TILE_SOLID solid, const TILE_SPECIAL special);

	void update(const unsigned int sprite, const TILE_SOLID solid, const TILE_SPECIAL special);	// update properties

	void draw(Window& window);

	const unsigned int parseSpriteID(const char id) const;
	const TILE_SOLID parseSolid(const char id) const;
	const TILE_SPECIAL parseSpecial(const char id) const;

	const char unparseSpriteID() const;
	const char unparseSolid() const;
	const char unparseSpecial() const;

	const unsigned int getLength() const;
	const unsigned int getScale() const;

private:
	void initSprite(ResourceManager<TEXTURES, sf::Texture>& tm, const unsigned int sprite, const int lvlw, const int pos);
	void initRect(const int lvlw, const int pos);

	void updateSprite();
	
};