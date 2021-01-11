#pragma once

#include <SFML/Graphics.hpp>

class Camera;

class Window
{
private:
	sf::RenderWindow window;

	Camera& camera;

public:
	const unsigned int WINDOW_WIDTH;
	const unsigned int WINDOW_HEIGHT;
	const unsigned int PIXEL_SIZE;

public:
	Window(const std::string& windowName, Camera& camera, const unsigned int width, const unsigned int height, const unsigned int size);

	void update();

	void beginDraw();
	void draw(const sf::Drawable& drawable);
	void endDraw();

	sf::RenderWindow& getWindow() { return this->window; }

	bool isOpen() const;
};