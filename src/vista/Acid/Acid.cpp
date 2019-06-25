#include "Acid.h"
#include "Idle_acid.h"
#include "../Window.h"
#include "../Constants.h"
#include "../Camara.h"
#include <string>
#include <iostream>
#include <typeinfo>

Acid::Acid(const Window &window) : dest_world(0, 0, 0, 0) {
	this->sprite = new IdleAcid(window);
}

int Acid::render(Camara &camara) {
	return camara.render(*this->sprite, dest_world);
}

void Acid::setDestWorld(float x, float y, float width, float height) {
	dest_world.set(x, y, width, height);
}

Acid::~Acid() {
	delete this->sprite;
}