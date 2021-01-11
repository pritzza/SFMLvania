#include "Camera.h"

Camera::Camera(const unsigned int W_W, const unsigned int W_H, const unsigned int ZOOM)
	:
	WIN_W(W_W),
	WIN_H(W_H),
	BASE_ZOOM(ZOOM)
{ 
	setView();
}

void Camera::setView()
{
	this->view.setCenter(xPos + WIN_W / BASE_ZOOM / 2, yPos + WIN_H / BASE_ZOOM / 2);
	this->view.setSize(WIN_W / BASE_ZOOM, WIN_H / BASE_ZOOM);
}

const sf::View& Camera::getView() const
{
	return this->view;
}
