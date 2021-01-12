#include "Camera.h"

#include "../util/Window.h"

Camera::Camera(const unsigned int W_W, const unsigned int W_H)
	:
	WIN_W(W_W),
	WIN_H(W_H)
{ 
	setView();
}

void Camera::setView()
{
	this->view.setCenter(xPos + WIN_W / Window::PIXEL_SIZE / 2, yPos + WIN_H / Window::PIXEL_SIZE / 2);

	this->view.setSize(WIN_W / Window::PIXEL_SIZE, WIN_H / Window::PIXEL_SIZE);
}

const sf::View& Camera::getView() const
{
	return this->view;
}
