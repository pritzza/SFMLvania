#include "GameState.h"

#include "../util/GameData.h"

#include "../events/StateEvent.h"

#include "../levels/Tile.h"

GameState::GameState(GameData& data, const std::string& levelFileName)
	:
	State(data),
	levelFileName(levelFileName)
{}

void GameState::init()
{
	this->initialized = true;

	ResourceManagers& rs = data.resourceManagers;

	//rs.textureManager.add(TEXTURES::TILESET);

	l.tileMap.load(levelFileName, rs.textureManager);

	data.camera.setView();

	p.init(*rs.textureManager.load(rs.textureManager.add(TEXTURES::SIMON)),
		0,  // id
		16,	// w
		33,  // h
		1,  // scale
		((l.tileMap.getWidth() * l.tileMap.getTile(0).getSize()) / 2) - (p.s.getPixelWidth()), // x
		((l.tileMap.getHeight() * l.tileMap.getTile(0).getSize()) / 2) - (p.s.getPixelHeight()),	// y
		4,	// key frames
		8	// tweens
	);
}

GameState::~GameState()
{
	data.resourceManagers.textureManager.remove(TEXTURES::TILESET);
	data.resourceManagers.textureManager.remove(TEXTURES::SIMON);
}

void GameState::handleInput()
{
	if (data.keyBoard.e.isTapped())
	{
		data.eventHandler.addEvent(new StateEvent(data, STATES::GAME, STATE_EVENT_TYPE::REMOVE));
		data.eventHandler.addEvent(new StateEvent(data, STATES::EDITOR, STATE_EVENT_TYPE::ADD, LEVEL::TEST));
		data.eventHandler.addEvent(new StateEvent(data, STATES::EDITOR, STATE_EVENT_TYPE::CHANGE));
	}

	if (data.keyBoard.space.isTapped())
		p.jump();

	if (data.keyBoard.w.isHeld() || data.keyBoard.w.isTapped())
		p.move(0, -1, data.keyBoard.w.isTapped());
	if (data.keyBoard.a.isHeld() || data.keyBoard.a.isTapped())
		p.move(-1, 0, data.keyBoard.a.isTapped());
	if (data.keyBoard.s.isHeld() || data.keyBoard.s.isTapped())
		p.move(0, 1, data.keyBoard.s.isTapped());
	if (data.keyBoard.d.isHeld() || data.keyBoard.d.isTapped())
		p.move(1, 0, data.keyBoard.d.isTapped());
}

void GameState::update(const float dt, const int f)
{
	p.update(dt, l.tileMap);

	data.camera.setPos(p.s.getPos().x + (p.s.getPixelWidth()/2), p.s.getPos().y + (p.s.getPixelHeight() / 2));
	data.camera.setView();
}

void GameState::render()
{
	Window& w = data.window;

	w.beginDraw();

	l.tileMap.draw(w);

	p.s.draw(w);

	w.endDraw();
}
