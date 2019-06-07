#include "Acid.h"
#include "Idle_acid.h"
#include "Touched_acid.h"
#include "../Window.h"
#include "../Constants.h"
#include "../Camara.h"
#include <string>
#include <iostream>
#include <typeinfo>

Acid::Acid(const Window &window) : window(window),
																	 dest_world(0, 0, 0, 0)
{
	this->sprite = new IdleAcid(this->window);
}

int Acid::render(Camara &camara)
{
	return camara.render(*this->sprite, dest_world);
}

void Acid::setTouched()
{
	if (strncmp(typeid(*this->sprite).name(), "11TouchedAcid", 13) != 0)
	{
		delete this->sprite;
		this->sprite = new TouchedAcid(window);
	}
}

void Acid::setDestWorld(float x, float y, float width, float height)
{
	dest_world.set(x, y, width, height);
}

void Acid::setIdle()
{
	if (strncmp(typeid(*this->sprite).name(), "8IdleAcid", 9) != 0)
	{
		delete this->sprite;
		this->sprite = new IdleAcid(window);
	}
}

Acid::~Acid()
{
}