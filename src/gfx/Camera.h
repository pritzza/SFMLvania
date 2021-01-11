#pragma once

#include <SFML/Graphics.hpp>

class Camera
{
private:
	sf::View view;

	int xPos{};
	int yPos{};

	const unsigned int WIN_H{};
	const unsigned int WIN_W{};

	const float BASE_ZOOM;	// always zoomed in atleast this much
	float zoomModifier{};

public:
	Camera(const unsigned int W_W, const unsigned int W_H, const unsigned int ZOOM);

	void setView();	// gets the camera pointed in the right place

	const sf::View& getView() const;
};