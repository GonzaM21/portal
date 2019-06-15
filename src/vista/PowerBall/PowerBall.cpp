#include "PowerBall.h"
#include "../Window.h"
#include "Flying_powerball.h"
#include "Hitting_powerball.h"
#include "Paw_powerball.h"
#include "../Constants.h"
#include <string>
#include <iostream>
#include <typeinfo>

PowerBall::PowerBall(const Window &window, const int &state, const int &direction) : window(window),
																																											 dest_world(0, 0, WIDTH_POWERBALL_FLYING, HEIGHT_POWERBALL_FLYING)
{
	if (state == 0)
	{
		this->sprite = new FlyingPowerBall(window, direction);
	}
	else if (state == 1)
	{
		setHitting();
	}
}

int PowerBall::render(Camara &camara)
{
	return camara.render(*sprite, dest_world);
}

void PowerBall::setDestWorld(float x, float y, float width, float height)
{
	dest_world.set(x, y, width, height);
}

void PowerBall::setHitting()
{
	if (strncmp(typeid(*this->sprite).name(), "16HittingPowerBall", 18) != 0)
	{
		delete this->sprite;
		this->sprite = new HittingPowerBall(window);
	}
}

bool PowerBall::isDone()
{
	return this->sprite->isDone();
}

bool PowerBall::hitted()
{
	return strncmp(typeid(*this->sprite).name(), "16HittingPowerBall", 18);
}

PowerBall::~PowerBall()
{
	delete this->sprite;
}