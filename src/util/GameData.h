#pragma once

#include "EventHandler.h"
#include "ResourceManagers.h"
#include "StateMachine.h"
#include "Window.h"

#include "../input/Mouse.h"
#include "../input/Keyboard.h"

#include "../gfx/Camera.h"

class GameData
{
public:
	GameData(const std::string& windowName, const unsigned int width, const unsigned int height, const unsigned int size, const unsigned int FPS)
		:
		window(windowName, camera, width, height, size),
		mouse(window.getWindow(), FPS),
		keyBoard(window.getWindow(), FPS),
		camera(width, height, size)
	{}

	StateMachine stateMachine;
	Window window;
	ResourceManagers resourceManagers;
	EventHandler eventHandler;

	Mouse mouse;
	KeyBoard keyBoard;

	Camera camera;
};