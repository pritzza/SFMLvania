#include "GameState.h"

#include "../util/GameData.h"

#include "../events/TileMapEvent.h"
#include "../events/StateEvent.h"

#include "../gfx/Sprite.h"

#include "../levels/TileData.h"

GameState::GameState(GameData& data, const std::string& levelFileName) 
	: 
	State(data),
	levelFileName(levelFileName)
{
	ResourceManagers& rs = data.resourceManagers;

	t.setFont(*rs.fontManager.load(FONTS::DEFAULT));
	t.setScale(.2f, .2f);
	t.setPosition(1, -1);

	rs.textureManager.add(TEXTURES::TILESET);

	l.tileMap.load(levelFileName, rs.textureManager);

	data.camera.setView();

	p.s.init(*rs.textureManager.load(rs.textureManager.add(TEXTURES::MONKEY2)), 0, 3, 2, 1, 0, 0);
}

GameState::~GameState()
{
	// todo
	//data.resourceManagers.textureManager.remove(TEXTURES::TILESET);
}

void GameState::handleInput()
{
	if (data.keyBoard.isActive(' '))
	{
		data.eventHandler.addEvent(new StateEvent(data, STATES::GAME,   STATE_EVENT_TYPE::REMOVE));
		data.eventHandler.addEvent(new StateEvent(data, STATES::EDITOR, STATE_EVENT_TYPE::ADD, LEVEL::TEST));
		data.eventHandler.addEvent(new StateEvent(data, STATES::EDITOR, STATE_EVENT_TYPE::CHANGE));
	}
			
}

void GameState::update(const float dt, const int f)
{
	t.setString("F: " + std::to_string(f) + "\nT: " + std::to_string(dt));
}

void GameState::render()
{
	Window& w = data.window;

	w.beginDraw();

	l.tileMap.draw(w);

	p.s.draw(w);

	w.draw(t);	//text

	w.endDraw();
}
