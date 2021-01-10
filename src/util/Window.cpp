#include "Window.h"

Window::Window(const std::string& windowName, const unsigned int width, const unsigned int height, const unsigned int size)
	:
	window(sf::VideoMode(width, height), windowName),
	WINDOW_WIDTH(width),
	WINDOW_HEIGHT(height),
	PIXEL_SIZE(size),
	view(sf::Vector2f(WINDOW_WIDTH / PIXEL_SIZE / 2u, WINDOW_HEIGHT / PIXEL_SIZE / 2u), sf::Vector2f(WINDOW_WIDTH / PIXEL_SIZE, WINDOW_HEIGHT / PIXEL_SIZE))
{
	//view.reset(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
	window.setView(view);
}

void Window::update()
{
	sf::Event event;

	if (this->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			this->window.close();
	}
}

void Window::beginDraw()
{
	this->window.clear(sf::Color(201, 17, 85));
}

void Window::draw(const sf::Drawable& drawable)
{
	this->window.draw(drawable);
}

void Window::endDraw()
{
	this->window.display();
}

bool Window::isOpen() const
{
	return window.isOpen();
}
