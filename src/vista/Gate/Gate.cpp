#include "Gate.h"
#include "../Window.h"
#include "Closed_gate.h"
#include "Opening_gate.h"
#include "Open_gate.h"
#include "Closing_gate.h"
#include <string>
#include <iostream>
#include <typeinfo>

Gate::Gate(const Window &window, const int &code) : window(window), dest_world(0, 0, 0, 0), code(code)
{
	this->states[3] = new OpeningGate(window, code);
	this->states[2] = new OpenGate(window, code);
	this->states[1] = new ClosingGate(window, code);
	this->states[0] = new ClosedGate(window, code);
	this->changeState[3] = &Gate::setOpening;
	this->changeState[2] = &Gate::setOpen;
	this->changeState[1] = &Gate::setClosing;
	this->changeState[0] = &Gate::setClosed;
	this->sprite = states[3];
}

int Gate::render(Camara &camara)
{
	return camara.render(*this->sprite, dest_world);
}

void Gate::setOpen()
{
	this->sprite->restart();
	is_open = true;
	is_closed = false;
	this->sprite = this->states[1];
}

bool Gate::isOpen()
{
	if (strncmp(typeid(*this->sprite).name(), "8OpenGate", 9) == 0 || (this->sprite->isDone() && strncmp(typeid(*this->sprite).name(), "11OpeningGate", 13) == 0))
	{
		return true;
	}
	return false;
}

void Gate::setClosed()
{
	this->sprite->restart();
	is_closed = true;
	is_open = false;
	this->sprite = this->states[3];
}

bool Gate::isClosed()
{
	if (strncmp(typeid(*this->sprite).name(), "10ClosedGate", 12) == 0 || (this->sprite->isDone() && strncmp(typeid(*this->sprite).name(), "11ClosingGate", 13) == 0))
	{
		return true;
	}
	return false;
}

void Gate::setOpening()
{
	if (strncmp(typeid(*this->sprite).name(), "8OpenGate", 9) != 0)
	{
		Rect src = this->sprite->getSrc();
		this->sprite->restart();
		this->sprite = this->states[0];
		this->sprite->setSrc(src);
	}
	else if (this->sprite->isDone() && strncmp(typeid(*this->sprite).name(), "11OpeningGate", 13) == 0)
	{
		this->sprite->restart();
		setOpen();
	}
}

void Gate::setClosing()
{
	if (strncmp(typeid(*this->sprite).name(), "10ClosedGate", 12) != 0)
	{
		Rect src = this->sprite->getSrc();
		this->sprite->restart();
		this->sprite = this->states[2];
		this->sprite->setSrc(src);
	}
	else if (this->sprite->isDone() && strncmp(typeid(*this->sprite).name(), "11ClosingGate", 13) == 0)
	{
		this->sprite->restart();
		setClosed();
	}
}
void Gate::setState(const int &state)
{
	(this->*(changeState[state]))();
}
void Gate::setDestWorld(float x, float y, float width, float height)
{
	dest_world.set(x, y, width, height);
}

Gate::~Gate()
{
	for (auto sprite : states)
	{
		delete sprite.second;
	}
}