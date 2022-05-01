#pragma once

#include "../levels/TileData.h"

enum class TILE_SOLID;
enum class TILE_SPECIAL;

template <class TT>	// tile type
class TileToken
{
public:
	const TT in;	// tile data represented IN program
	const char out;	// tile data represented OUT of program in level data

public:
	TileToken(TT tt, char c)
		:
		in{ tt },
		out{ c }
	{}
};

class LevelParser
{
public:
	const TileToken<TILE_SPRITE_ID> ids[TileData::NUM_IDS]
	{
		TileToken<TILE_SPRITE_ID>(TILE_SPRITE_ID::AIR,		' '),
		TileToken<TILE_SPRITE_ID>(TILE_SPRITE_ID::BRICK,	'#'),
		TileToken<TILE_SPRITE_ID>(TILE_SPRITE_ID::GROUND,	'o'),
		TileToken<TILE_SPRITE_ID>(TILE_SPRITE_ID::PLATFORM,	'-'),
		TileToken<TILE_SPRITE_ID>(TILE_SPRITE_ID::FACE,		'v'),
		TileToken<TILE_SPRITE_ID>(TILE_SPRITE_ID::BARREL,	'b')
	};

	const TileToken<TILE_SOLID> solids[TileData::NUM_SOLIDS]
	{
		TileToken<TILE_SOLID>(TILE_SOLID::NOT_SOLID,	' '),
		TileToken<TILE_SOLID>(TILE_SOLID::PLATFORM,		'-'),
		TileToken<TILE_SOLID>(TILE_SOLID::SOLID,		'.')
	};

	const TileToken<TILE_SPECIAL> specials[TileData::NUM_SPECIALS]
	{
		TileToken<TILE_SPECIAL>(TILE_SPECIAL::NONE,		' ')
	};

public:
	const unsigned int getIndex(const unsigned int i) const;
	const unsigned int getIndex(const TILE_SOLID i) const;
	const unsigned int getIndex(const TILE_SPECIAL i) const;

	const unsigned int getSpriteIndex(const char id) const;
	const unsigned int getSolidIndex(const char id) const;
	const unsigned int getSpecialIndex(const char id) const;

	// takes index and returns 'in' of value of corresponding tile
	const unsigned int parseSpriteID(const unsigned int id) const;
	const TILE_SOLID parseSolid(const unsigned int id) const;
	const TILE_SPECIAL parseSpecial(const unsigned int id) const;

	// takes index and returns 'out' of value of corresponding tile
	const char unparseSpriteID(const unsigned int id) const;
	const char unparseSolid(const unsigned int id) const;
	const char unparseSpecial(const unsigned int id) const;
};