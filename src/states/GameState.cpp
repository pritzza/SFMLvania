#include "GameState.h"

#include "MenuState.h"

#include "../util/GameData.h"
#include "../util/ResourceManager.h"

#include "../events/TileMapEvent.h"

#include "../gfx/Sprite.h"

#include "../levels/Tile.h"

#include <string>

#include <iostream>

GameState::GameState(GameData& data) 
	: 
	State(data)
{
	ResourceManagers& rs = data.resourceManagers;

	s.setTexture(*rs.textureManager.load(rs.textureManager.add(TEXTURES::DEFAULT)));
	//s.setTextureRect(sf::IntRect(w * cycle, 0, w * (cycle + 1), h));
	s.setPosition(data.window.WINDOW_WIDTH / 2.f, data.window.WINDOW_HEIGHT / 2.f);
	s.setScale(1.0f, 1.0f);

	t.setFont(*rs.fontManager.load(rs.fontManager.add(FONTS::DEFAULT)));
	t.setPosition(0,0);
	//t.setScale(.5,.5);

	rs.textureManager.add(TEXTURES::TILES);

	l.tileMap.load("res/levels/test1.txt", rs.textureManager);

	data.eventHandler.addEvent(new TileMapEvent(l.tileMap, 3, TILE_SPRITE_ID::BRICK, TILE_SOLID::NOT_SOLID, TILE_SPECIAL::NONE));
}

GameState::~GameState()
{
	l.tileMap.save("res/levels/test1.txt");
}

void GameState::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{

	}

	const int& mx = sf::Mouse::getPosition(data.window.getWindow()).x;
	const int& my = sf::Mouse::getPosition(data.window.getWindow()).y;
	const int& mapw = l.tileMap.getWidth() * l.tileMap.getTile(0).getLength() * l.tileMap.getTile(0).getScale() * data.window.PIXEL_SIZE * Sprite::SPRITE_SIZE;
	const int& maph = l.tileMap.getHeight() * l.tileMap.getTile(0).getLength() * l.tileMap.getTile(0).getScale() * data.window.PIXEL_SIZE * Sprite::SPRITE_SIZE;

	if (mx > 0 && mx < mapw &&
		my > 0 && my < maph &&
		sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		const int& x = sf::Mouse::getPosition(data.window.getWindow()).x / (l.tileMap.getTile(0).getLength() * l.tileMap.getTile(0).getScale() * data.window.PIXEL_SIZE * Sprite::SPRITE_SIZE);
		const int& y = sf::Mouse::getPosition(data.window.getWindow()).y / (l.tileMap.getTile(0).getLength() * l.tileMap.getTile(0).getScale() * data.window.PIXEL_SIZE * Sprite::SPRITE_SIZE);

		data.eventHandler.addEvent(new TileMapEvent(l.tileMap, x + (y * l.tileMap.getWidth()), TILE_SPRITE_ID::BRICK, TILE_SOLID::NOT_SOLID, TILE_SPECIAL::NONE));
	}
			
}

void GameState::update(const float dt, const int f)
{
	//const int& x = sf::Mouse::getPosition(data.window.getWindow()).x / (l.tileMap.getTile(0).getLength() * l.tileMap.getTile(0).getScale() * data.window.PIXEL_SIZE * Sprite::SPRITE_SIZE);
	//const int& y = sf::Mouse::getPosition(data.window.getWindow()).y / (l.tileMap.getTile(0).getLength() * l.tileMap.getTile(0).getScale() * data.window.PIXEL_SIZE * Sprite::SPRITE_SIZE);
	//
	//t.setString(
	//	"x: " + std::to_string(x) + 
	//	"y: " + std::to_string(y)
	//);
}

void GameState::render()
{
	Window& w = data.window;

	w.beginDraw();

	l.tileMap.draw(w);

	//w.draw(s);
	w.draw(t);

	w.endDraw();
}
