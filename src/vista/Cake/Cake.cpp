#include "Cake.h"
#include "../Window.h"
#include "../Constants.h"
#include "Cake_cake_sprite.h"
#include <string>
#include <iostream>
#include <typeinfo>

Cake::Cake(const Window &window) : dest_world(0, 0, 0, 0) {
  this->sprite = new CakeSprite(window);
}

int Cake::render(Camara &camara) {
  return camara.render(*sprite, dest_world);
}

void Cake::setDestWorld(float x, float y, float width, float height) {
  dest_world.set(x, y, width, height);
}

Cake::~Cake() {
  delete this->sprite;
}