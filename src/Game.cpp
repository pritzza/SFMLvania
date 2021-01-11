#include "Game.h"

#include "util/GameData.h"
#include "events/StateEvent.h"

Game::Game(const std::string& windowName, const unsigned int width, const unsigned int height, const unsigned int size, const unsigned int fps)
	:
	data(windowName, width, height, size, fps),
	FPS(fps)
{
	data.eventHandler.addEvent(new StateEvent(data, STATES::EDITOR, STATE_EVENT_TYPE::ADD, LEVEL::TEST));	// add starting state
	data.eventHandler.addEvent(new StateEvent(data, STATES::EDITOR, STATE_EVENT_TYPE::CHANGE));		// change to it

	// load default resources
	data.resourceManagers.textureManager.add(TEXTURES::DEFAULT);
	data.resourceManagers.fontManager.add(FONTS::DEFAULT);
	//data.resourceManagers.soundManager.add(SOUNDS::DEFAULT);
}

void Game::gameLoop()
{
	unsigned int frame{};
	float delta = 0.f;

	while (isRunning())
	{
		clock.restart();

		data.eventHandler.processEvents();

		data.stateMachine.processStateChange();

		data.window.update();	// checks if window has been closed
		data.mouse.update();
		data.keyBoard.update();

		if (data.stateMachine.currentState() != nullptr)
		{
			data.stateMachine.currentState()->handleInput();
			data.stateMachine.currentState()->update(delta, frame);
			data.stateMachine.currentState()->render();
		}

		delta = clock.getElapsedTime().asSeconds();

		sf::sleep(sf::seconds(1.f/FPS - delta));

		++frame;
	}
}

bool Game::isRunning() const
{
	return data.window.isOpen();
}