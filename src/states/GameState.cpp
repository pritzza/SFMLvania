#include "GameState.h"

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

GameState::GameState(GameData& data, const std::string& levelFileName) 
	: 
	State(data)
{
	ResourceManagers& rs = data.resourceManagers;

	t.setFont(*rs.fontManager.load(rs.fontManager.add(FONTS::DEFAULT)));
	t.setScale(.2f, .2f);
	t.setPosition(1, -1);

	rs.textureManager.add(TEXTURES::TILES);

	l.tileMap.load(levelFileName, rs.textureManager);
}

GameState::~GameState()
{
}

void GameState::handleInput()
{
	if (data.keyBoard.isActive(' '))
	{
		data.eventHandler.addEvent(new StateEvent(data, STATES::GAME, STATE_EVENT_TYPE::REMOVE));
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

	w.draw(t);

	w.endDraw();
}
