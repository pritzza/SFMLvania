#pragma once

enum class TILE_SOLID;
enum class TILE_SPECIAL;

class LevelParser
{
public:
	// for loading tile data from file
	const unsigned int parseSpriteID(const char id) const;
	const TILE_SOLID parseSolid(const char id) const;
	const TILE_SPECIAL parseSpecial(const char id) const;

	// for saving tile data to file
	const char unparseSpriteID(const unsigned int id) const;
	const char unparseSolid(const TILE_SOLID solid) const;
	const char unparseSpecial(const TILE_SPECIAL special) const;
};