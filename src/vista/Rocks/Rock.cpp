#include "Rock.h"
#include "../Window.h"
#include "../Constants.h"
#include "Rock_rock_sprite.h"
#include <string>
#include <iostream>
#include <typeinfo>

Rock::Rock(const Window &window) : dest_world(0, 0, 0, 0) {
  this->sprite = new RockSprite(window);
}

int Rock::render(Camara &camara) {
  return camara.render(*sprite, dest_world);
}

void Rock::setDestWorld(float x, float y, float width, float height) {
  dest_world.set(x, y, width, height);
}

Rock::~Rock() {
  delete this->sprite;
}