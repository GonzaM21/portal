#include "Emitter.h"
#include "../Window.h"
#include "../Constants.h"
#include <string>
#include <iostream>

Emitter::Emitter(const Window &window, const int &code, const int &state) : dest_world(0, 0, 0, 0), sprite(window, code) {
	if (state == 0) {
		inactive = new TargetSprite(window, 1);
	} else {
		inactive = new TargetSprite(window, 0);
	}
}

int Emitter::render(Camara &camara) {
	camara.render(sprite, dest_world); 
	return camara.render(*inactive, dest_world);
}

void Emitter::setDestWorld(float x, float y, float width, float height) {
	dest_world.set(x, y, width, height);
}

void Emitter::setState(const int& state) {
	inactive->setState(std::abs(state-1));
}

Emitter::~Emitter() {
}