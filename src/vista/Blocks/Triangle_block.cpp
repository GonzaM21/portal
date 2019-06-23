#include "Triangle_block.h"
#include "../Window.h"
#include "../Constants.h"
#include <string>
#include <iostream>

TriangleBlock::TriangleBlock(const Window &window, const int& code) : sprite(window,code), dest_world(0, 0, 0, 0) {
}

int TriangleBlock::render(Camara &camara) {
  return camara.render(this->sprite, dest_world);
}

void TriangleBlock::setDestWorld(float x, float y, float width, float height) {
  dest_world.set(x, y, width, height);
}

TriangleBlock::~TriangleBlock() {
}