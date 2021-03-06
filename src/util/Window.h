#pragma once

#include <SFML/Graphics.hpp>

class Camera;

class Window
{
public:
	static constexpr unsigned int PIXEL_SIZE{ 4 };

private:
	sf::RenderWindow window;

	Camera& camera;

	bool focused{ true };

public:
	const unsigned int WINDOW_WIDTH;
	const unsigned int WINDOW_HEIGHT;

public:
	Window(const std::string& windowName, Camera& camera, const unsigned int width, const unsigned int height);

	void update();

	void beginDraw();
	void draw(const sf::Drawable& drawable);
	void endDraw();

	sf::RenderWindow& getWindow();

	const bool isOpen() const;
	const bool isFocused() const;
};