#include "Window.h"

#include "../gfx/Camera.h"

Window::Window(const std::string& windowName, Camera& camera, const unsigned int width, const unsigned int height, const unsigned int size)
	:
	window(sf::VideoMode(width, height), windowName),
	camera(camera),
	WINDOW_WIDTH(width),
	WINDOW_HEIGHT(height),
	PIXEL_SIZE(size)
{
}

void Window::update()
{
	window.setView(camera.getView());

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
