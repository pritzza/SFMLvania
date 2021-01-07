#include "GameState.h"

#include "MenuState.h"

#include "../util/GameData.h"
#include "../util/ResourceManager.h"

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
	t.setPosition(1, 1);

	l.tileMap.load("res/levels/test3.txt", rs.textureManager);
}

GameState::~GameState()
{

}

void GameState::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{

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

	//w.draw(s);
	//w.draw(t);

	w.endDraw();
}
