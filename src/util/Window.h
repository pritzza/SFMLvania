#pragma once

#include <SFML/Graphics.hpp>

class Window
{
private:
	sf::RenderWindow window;

public:
	const unsigned int WINDOW_WIDTH;
	const unsigned int WINDOW_HEIGHT;
	const unsigned int PIXEL_SIZE;

	const sf::View view;

public:
	Window(const std::string& windowName, const unsigned int width, const unsigned int height, const unsigned int size);

	void update();

	void beginDraw();
	void draw(const sf::Drawable& drawable);
	void endDraw();

	bool isOpen() const;
};