#include "PowerBall.h"
#include "../Window.h"
#include "Flying_powerball.h"
#include "Hitting_powerball.h"
#include "Paw_powerball.h"
#include "../Constants.h"
#include <string>
#include <iostream>
#include <typeinfo>

PowerBall::PowerBall(const Window &window, const int &direction) : dest_world(0, 0, WIDTH_POWERBALL_FLYING, HEIGHT_POWERBALL_FLYING) {	
	this->sprite = new FlyingPowerBall(window, direction);
}

int PowerBall::render(Camara &camara) {
	return camara.render(*sprite, dest_world);
}

void PowerBall::setDestWorld(float x, float y, float width, float height) {
	dest_world.set(x, y, width, height);
}

bool PowerBall::isDone() {
	return this->sprite->isDone();
}

PowerBall::~PowerBall(){
	delete this->sprite;
}