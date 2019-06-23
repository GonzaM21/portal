#include "Button.h"
#include "../Window.h"
#include "../Constants.h"
#include "ButtonOff_button.h"
#include "ButtonOn_button.h"
#include <string>
#include <iostream>
#include <typeinfo>

Button::Button(const Window &window, const int &state) :	dest_world(0, 0, 0, 0) {
	this->states[0] = new ButtonOff(window);
	this->states[1] = new ButtonOn(window);
	this->sprite = this->states[state];
}

int Button::render(Camara &camara) {
	return camara.render(*this->sprite, dest_world);
}

void Button::setDestWorld(float x, float y, float width, float height) {
	dest_world.set(x, y, width, height);
}

void Button::setState(const int& state) {
	this->sprite = this->states[state];
}

Button::~Button() {
	delete this->sprite;
}