#pragma once

// the data for the different properties of tailes, including their texture id, collision type, and special properties

enum TILE_SPRITE_ID
{
	MISSING_TILE,
	AIR,
	BRICK,
	GROUND,
	PLATFORM,
	FACE,
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
	void iterateSprite(unsigned int& id)
	{
		switch (id)
		{
		case TILE_SPRITE_ID::AIR:		id = TILE_SPRITE_ID::BRICK;		 break;
		case TILE_SPRITE_ID::BRICK:		id = TILE_SPRITE_ID::GROUND;	 break;
		case TILE_SPRITE_ID::GROUND:	id = TILE_SPRITE_ID::PLATFORM;	 break;
		case TILE_SPRITE_ID::PLATFORM:	id = TILE_SPRITE_ID::FACE;		 break;	// remember the break statements
		case TILE_SPRITE_ID::FACE:		// skip and cycle back						
		default:						id = TILE_SPRITE_ID::AIR;		 break;
		}
	}

	void iterateSolid(TILE_SOLID& solid)
	{
		switch (solid)
		{
		case TILE_SOLID::SOLID:			solid = TILE_SOLID::NOT_SOLID;	break;
		case TILE_SOLID::NOT_SOLID:		// skip and cycle back					
		default:						solid = TILE_SOLID::SOLID;		break;
		}
	}

	void iterateSpecial(TILE_SPECIAL& special)
	{
		switch (special)
		{
		case TILE_SPECIAL::NONE:			
		default:							break;
		}
	}

	void iterateProperty(unsigned int& property)
	{
		switch (property)
		{
		case TILE_PROPERTY::SPRITE:		property = TILE_PROPERTY::SOLID; break;
		case TILE_PROPERTY::SOLID:		property = TILE_PROPERTY::SPECIAL; break;
		case TILE_PROPERTY::SPECIAL:	property = TILE_PROPERTY::SPRITE; break;
		}
	}
};