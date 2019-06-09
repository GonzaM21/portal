#include "Button.h"
#include "../Window.h"
#include "../Constants.h"
#include "ButtonOff_button.h"
#include "ButtonOn_button.h"
#include <string>
#include <iostream>
#include <typeinfo>

Button::Button(const Window &window, const int &state) : window(window),
																												 dest_world(0, 0, WIDTH_POWERBALL_FLYING, HEIGHT_POWERBALL_FLYING)
{
	this->states[0] = new ButtonOff(window);
	this->states[1] = new ButtonOn(window);
	this->sprite = this->states[0];
	this->changeState[0] = &Button::setUnpressed;
	this->changeState[1] = &Button::setPressed;
}

int Button::render(Camara &camara)
{
	return camara.render(*this->sprite, dest_world);
}

void Button::setDestWorld(float x, float y, float width, float height)
{
	dest_world.set(x, y, width, height);
}

void Button::setPressed()
{
	this->sprite = this->states[1];
}

void Button::setUnpressed()
{
	this->sprite = this->states[0];
}

void Button::setState(const int state)
{
	(this->*(changeState[state]))();
}

Button::~Button()
{
	delete this->sprite;
}