#include "EditorState.h"

#include "MenuState.h"

#include "../util/GameData.h"
#include "../util/ResourceManager.h"

#include "../events/TileMapEvent.h"
#include "../events/StateEvent.h"

#include "../gfx/Sprite.h"

#include "../levels/Tile.h"
#include "../levels/TileData.h"

#include <string>

#include <iostream>

EditorState::EditorState(GameData& data, const std::string& levelFileName)
	:
	State(data)
{
	ResourceManagers& rs = data.resourceManagers;

	t.setFont(*rs.fontManager.load(rs.fontManager.add(FONTS::DEFAULT)));
	t.setScale(.2f, .2f);
	t.setPosition(1, -1);

	rs.textureManager.add(TEXTURES::TILES);

	l.tileMap.load(levelFileName, rs.textureManager);

	ttProperty = TILE_PROPERTY::SPRITE;
	ttSpriteID = TILE_SPRITE_ID::BRICK;
	ttSolid = TILE_SOLID::NOT_SOLID;
	ttSpecial = TILE_SPECIAL::NONE;

	tempTile.init(rs.textureManager, 1, 0, this->ttSpriteID, this->ttSolid, this->ttSpecial);
	tempTile.initRect(3, 255 * (3.f / 4.f));

	//l.player.s.init(*rs.textureManager.load(rs.textureManager.add(TEXTURES::DEFAULT)), 0, 18, 13, 1, 0, 0);
}

EditorState::~EditorState()
{
	l.tileMap.save("res/levels/test1.txt");
}

void EditorState::handleInput()
{
	if (data.keyBoard.isActive(' '))
	{
		data.eventHandler.addEvent(new StateEvent(data, STATES::EDITOR, STATE_EVENT_TYPE::REMOVE));
		data.eventHandler.addEvent(new StateEvent(data, STATES::GAME, STATE_EVENT_TYPE::ADD, LEVEL::TEST));
		data.eventHandler.addEvent(new StateEvent(data, STATES::GAME, STATE_EVENT_TYPE::CHANGE));
	}

	if (data.keyBoard.isActive('S'))
	{
		TileData td;
		td.iterateProperty(ttProperty);
	}

	if (data.mouse.isClicked(MOUSE::RIGHT))
	{
		TileData td;
		switch (ttProperty)
		{ 
		case TILE_PROPERTY::SPRITE:		td.iterateSprite(this->ttSpriteID);		break;
		case TILE_PROPERTY::SOLID:		td.iterateSolid(this->ttSolid);			break;
		case TILE_PROPERTY::SPECIAL:	td.iterateSpecial(this->ttSpecial);		break;
		}
		this->tempTile.update(this->ttSpriteID, this->ttSolid, this->ttSpecial);
		this->tempTile.initRect(3, 255 * (3.f / 4.f));
	}

	const int& mx = data.mouse.getPos().x;
	const int& my = data.mouse.getPos().y;

	TileMap& tm = l.tileMap;
	Tile& t = tm.getTile(0);

	const int& ts = t.getLength() * t.getScale() * data.window.PIXEL_SIZE * Sprite::SPRITE_SIZE;	// tile size

	if (mx > 0 && mx < ts * tm.getWidth() &&
		my > 0 && my < ts * tm.getHeight() &&
		(data.mouse.isClicked(MOUSE::LEFT) || data.mouse.isHeld(MOUSE::LEFT)))
	{
		const int& x = data.mouse.getPos().x / ts;
		const int& y = data.mouse.getPos().y / ts;

		data.eventHandler.addEvent(new TileMapEvent(l.tileMap, x + (y * tm.getWidth()), this->ttSpriteID, this->ttSolid, this->ttSpecial));
	}
}

void EditorState::update(const float dt, const int f)
{
	const int& ts = l.tileMap.getTile(0).getLength() * l.tileMap.getTile(0).getScale() * data.window.PIXEL_SIZE * Sprite::SPRITE_SIZE;	// tile size

	const int& x = data.mouse.getPos().x / ts;
	const int& y = data.mouse.getPos().y / ts;

	this->tempTile.setPosition(x, y);

	t.setString(
		"x: " + std::to_string(x) +
		"y: " + std::to_string(y)
	);

	if (data.keyBoard.isActive('S'))
		t.setString(
			"active"
		);
}

void EditorState::render()
{
	Window& w = data.window;

	w.beginDraw();

	l.tileMap.draw(w, true);

	tempTile.draw(w, true);

	//l.player.s.draw(w, true);

	w.draw(t);

	w.endDraw();
}
