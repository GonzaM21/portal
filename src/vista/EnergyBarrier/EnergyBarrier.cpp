#include "EnergyBarrier.h"
#include "EnergyBarrier_sprite.h"
#include <string>
#include <iostream>
#include <typeinfo>

EnergyBarrier::EnergyBarrier(const Window &window, const int &code) : dest_world(0, 0, 0, 0) {
  this->sprite = new EnergyBarrierSprite(window, code);
}

int EnergyBarrier::render(Camara &camara) {
  return camara.render(*this->sprite, dest_world);
}

void EnergyBarrier::setDestWorld(float x, float y, float width, float height) {
  dest_world.set(x, y, width, height);
}

EnergyBarrier::~EnergyBarrier() {
  delete sprite;
}