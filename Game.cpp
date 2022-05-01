#include "Game.h"

#include "events/StateEvent.h"

Game::Game(const std::string& windowName, const unsigned int width, const unsigned int height, const unsigned int fps)
	:
	data(windowName, width, height, fps),
	FPS(fps)
{
	EventHandler& eh{ data.eventHandler };
	eh.addEvent(std::make_shared<StateEvent>(data, STATES::EDITOR, STATE_EVENT_TYPE::ADD, LEVEL::CHAMBER));	// add starting state
	eh.addEvent(std::make_shared<StateEvent>(data, STATES::EDITOR, STATE_EVENT_TYPE::CHANGE));		// change to it

	// load default resources
	ResourceManagers& rs{ data.resourceManagers };
	rs.textureManager.add(TEXTURES::DEFAULT);
	rs.fontManager.add(FONTS::DEFAULT);
	//rs.soundManager.add(SOUNDS::DEFAULT);
}

void Game::gameLoop()
{
	unsigned int frame{};
	float delta = 0.f;

	GameData& d{ data };

	while (isRunning())
	{
		clock.restart();

		d.eventHandler.processEvents();

		d.stateMachine.processStateChange();

		d.window.update();	// checks if window has been closed

		if (d.window.isFocused())
		{
			d.mouse.update();
			d.keyBoard.update();

			if (d.stateMachine.currentState() != nullptr)
			{
				if (!d.stateMachine.currentState()->isInit())	// if state hasnt been initialized, initialize it
					d.stateMachine.currentState()->init();

				d.stateMachine.currentState()->handleInput();
				d.stateMachine.currentState()->update(delta, frame);
				d.stateMachine.currentState()->render();
			}
		}

		delta = clock.getElapsedTime().asSeconds();	// processing time
		sf::sleep(sf::seconds(1.f/FPS - delta));
		++frame;
		
		delta = clock.getElapsedTime().asSeconds();	// total gameloop time
	}
}

bool Game::isRunning() const
{
	return data.window.isOpen();
}