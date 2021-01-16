#include "MenuState.h"

#include "../util/GameData.h"
#include "../util/ResourceManager.h"

#include <SFML/Graphics.hpp>

#include <iostream>

MenuState::MenuState(GameData& data)
	:
	State(data)
{}

void MenuState::init()
{
	this->initialized = true;
}

MenuState::~MenuState()
{
	
}

void MenuState::handleInput()
{

}

void MenuState::update(const float dt, const int f)
{
}

void MenuState::render()
{
	data.window.beginDraw();

	//data.window.draw();

	data.window.endDraw();
}
