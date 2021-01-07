#pragma once

#include "EventHandler.h"
#include "ResourceManagers.h"
#include "StateMachine.h"
#include "Window.h"

class GameData
{
public:
	GameData(const std::string& windowName, const unsigned int width, const unsigned int height, const unsigned int size)
		:
		window(windowName, width, height, size) 
	{}

	StateMachine stateMachine;
	Window window;
	ResourceManagers resourceManagers;
	EventHandler eventHandler;
};