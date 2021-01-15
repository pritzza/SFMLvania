#pragma once

// the data for the different properties of tailes, including their texture id, collision type, and special properties

enum TILE_SPRITE_ID
{
	AIR,
	BRICK,
	GROUND,
	PLATFORM,
	FACE,
	BARREL,
};

enum class TILE_SOLID
{
	SOLID,
	NOT_SOLID,
	PLATFORM,
	//STAIRS,
};

enum class TILE_SPECIAL
{
	NONE,
	//BAT_SPAWNER,
};

// for editor
enum TILE_PROPERTY
{
	SPRITE,
	SOLID,
	SPECIAL
};

class TileData
{
public:
	static constexpr unsigned int NUM_IDS{ 6 };
	static constexpr unsigned int NUM_SOLIDS{ 3 };
	static constexpr unsigned int NUM_SPECIALS{ 1 };

public:
	void iterateSprite(unsigned int& id);
	void iterateSolid(TILE_SOLID& solid);
	void iterateSpecial(TILE_SPECIAL& special);
	void iterateProperty(unsigned int& property);
};