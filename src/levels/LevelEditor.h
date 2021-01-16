#pragma once

#include "Tile.h"
#include "TileData.h"

template <class Key, class Resource>
class ResourceManager;

class EventHandler;

class TileMap;

class LevelEditor
{
private:
	TileData td;

	// tempTile is the tile visualization of the tile data you have selected in the editor
	Tile cursorTile;

	TILE_PROPERTY property =	TILE_PROPERTY::SPRITE;	// which property you're selected to iterate through
	unsigned int spriteID =		TILE_SPRITE_ID::BRICK;
	TILE_SOLID solid =			TILE_SOLID::NOT_SOLID;
	TILE_SPECIAL special =		TILE_SPECIAL::NONE;

private:
	void updateCursorTilePos(const int x, const int y);
	void updateCursorTile();

public:
	void init(ResourceManager<TEXTURES, sf::Texture>& tm);

	void iterateElements();
	void iterateProperties();

	void placeTile(EventHandler& eh, TileMap& tm, const int mx, const int my);
	void copyTile(const Tile& t);
	Tile& getTile();

	void update(const int x, const int y);
};