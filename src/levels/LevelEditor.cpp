#include "LevelEditor.h"

#include "TileData.h"
#include "TileMap.h"

#include "../events/TileMapEvent.h"
#include "../util/EventHandler.h"

void LevelEditor::init(ResourceManager<TEXTURES, sf::Texture>& tm)
{
	cursorTile.init(tm, 1, 0, spriteID, solid, special);
	updateCursorTile();
}

void LevelEditor::iterateElements()
{
	switch (property)
	{
	case TILE_PROPERTY::SPRITE:		td.iterateSprite(spriteID);		break;
	case TILE_PROPERTY::SOLID:		td.iterateSolid(solid);			break;
	case TILE_PROPERTY::SPECIAL:	td.iterateSpecial(special);		break;
	}
	updateCursorTile();
}

void LevelEditor::iterateProperties()
{
	td.iterateProperty(this->property);
}

void LevelEditor::copyTile(const Tile& t)
{
	spriteID = t.getSpriteID();
	solid = t.getSolid();
	special = t.getSpecial();

	updateCursorTile();
}

Tile& LevelEditor::getTile()
{
	return this->cursorTile;
}

void LevelEditor::placeTile(EventHandler& eh, TileMap& tm, const int mx, const int my)
{
	eh.addEvent(new TileMapEvent(tm, mx + (my * tm.getWidth()), this->spriteID, this->solid, this->special));
}

void LevelEditor::updateCursorTile()
{
	cursorTile.setTile(spriteID, solid, special);
	cursorTile.setOutlineThickness(3);
}

void LevelEditor::updateCursorTilePos(const int x, const int y)
{
	cursorTile.setPosition(x, y);
}

void LevelEditor::update(const int x, const int y)
{
	updateCursorTilePos(x, y);
}
