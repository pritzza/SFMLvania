#include "EditorState.h"

#include "../util/GameData.h"

#include "../events/TileMapEvent.h"
#include "../events/StateEvent.h"

#include "../gfx/Sprite.h"

#include "../levels/TileData.h"

EditorState::EditorState(GameData& data, const std::string& levelFileName)
	:
	State(data),
	levelFileName(levelFileName)
{
	ResourceManagers& rs = data.resourceManagers;

	// sets up debug text
	t.setFont(*rs.fontManager.load(FONTS::DEFAULT));
	t.setScale(.2f, .2f);
	t.setPosition(1, -1);

	rs.textureManager.add(TEXTURES::TILESET);

	l.tileMap.load(levelFileName, rs.textureManager);

	// init temp tile
	ttProperty = TILE_PROPERTY::SPRITE;
	ttSpriteID = TILE_SPRITE_ID::BRICK;
	ttSolid = TILE_SOLID::NOT_SOLID;
	ttSpecial = TILE_SPECIAL::NONE;

	tempTile.init(rs.textureManager, 1, 0, this->ttSpriteID, this->ttSolid, this->ttSpecial);
	tempTile.setOutlineThickness(2);

	data.camera.setView();


	p.s.init(*rs.textureManager.load(rs.textureManager.add(TEXTURES::MONKEY2)),
		0,  // id
		3,	// w
		2,  // h
		1,  // scale
		(data.window.WINDOW_WIDTH / data.window.PIXEL_SIZE / 2), // x
		0	// y
	);
}

EditorState::~EditorState()
{
	l.tileMap.save(this->levelFileName);

	//data.resourceManagers.textureManager.remove(TEXTURES::TILESET);
}

void EditorState::handleInput()
{
	if (data.keyBoard.isActive('e'))
	{
		l.tileMap.save(this->levelFileName);
		data.eventHandler.addEvent(new StateEvent(data, STATES::EDITOR, STATE_EVENT_TYPE::REMOVE));
		data.eventHandler.addEvent(new StateEvent(data, STATES::GAME,   STATE_EVENT_TYPE::ADD, LEVEL::TEST));
		data.eventHandler.addEvent(new StateEvent(data, STATES::GAME,   STATE_EVENT_TYPE::CHANGE));
	}

	if (data.keyBoard.isActive('S'))
	{
		TileData td;
		td.iterateProperty(ttProperty);
	}

	if (data.keyBoard.isActive(' '))
	{
		//p.jump();
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
		this->tempTile.setTile(this->ttSpriteID, this->ttSolid, this->ttSpecial);
	}

	const int& mx = data.mouse.getPos().x;
	const int& my = data.mouse.getPos().y;

	TileMap& tm = l.tileMap;
	Tile& t = tm.getTile(0);

	const int& ts = Tile::LENGTH * Tile::SCALE * data.window.PIXEL_SIZE * Sprite::SPRITE_SIZE;	// tile size

	if (mx > 0 && mx < ts * tm.getWidth() &&
		my > 0 && my < ts * tm.getHeight() &&
		(data.mouse.isClicked(MOUSE::LEFT) || data.mouse.isHeld(MOUSE::LEFT)))
	{
		const int& x = data.mouse.getPos().x / ts;
		const int& y = data.mouse.getPos().y / ts;

		data.eventHandler.addEvent(new TileMapEvent(l.tileMap, x + (y * tm.getWidth()), this->ttSpriteID, this->ttSolid, this->ttSpecial));
	}


	if (data.keyBoard.isActive('w'))
		p.move(0, -1);
	if (data.keyBoard.isActive('a'))
		p.move(-1, 0);
	if (data.keyBoard.isActive('s'))
		p.move(0, 1);
	if (data.keyBoard.isActive('d'))
		p.move(1, 0);
}

void EditorState::update(const float dt, const int f)
{
	const int& ts = Tile::LENGTH * Tile::SCALE * data.window.PIXEL_SIZE * Sprite::SPRITE_SIZE;	// tile size

	const int& x = data.mouse.getPos().x / ts;
	const int& y = data.mouse.getPos().y / ts;

	this->tempTile.setPosition(x, y);

	for (int i = 0; i < l.tileMap.getHeight() * l.tileMap.getWidth(); ++i)
		l.tileMap.getTile(i).setOutlineThickness(1);

	t.setString(
		"x: " + std::to_string(x) +
		"y: " + std::to_string(y)
	);

	if (data.keyBoard.isActive('S'))
		t.setString(
			"active"
		);

	p.update(dt, l.tileMap);
}

void EditorState::render()
{
	Window& w = data.window;

	w.beginDraw();

	l.tileMap.draw(w, true);

	tempTile.draw(w, true);

	p.s.draw(w, true);

	w.draw(t);

	w.endDraw();
}
