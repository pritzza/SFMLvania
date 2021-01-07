#include "Game.h"

#include "util/GameData.h"
#include "states/GameState.h"

Game::Game(const std::string& windowName, const unsigned int width, const unsigned int height, const unsigned int size)
	:
	data(windowName, width, height, size)
{
	data.stateMachine.addState(STATES::MAIN, new GameState(data));	// add starting state
	data.stateMachine.changeState(STATES::MAIN);		// change to it
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