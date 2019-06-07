#include "Stone_block.h"
#include "../Window.h"
#include "../Constants.h"
#include <string>
#include <iostream>

StoneBlock::StoneBlock(const Window &window) : sprite(window), dest_world(0, 0, 0, 0)
{
}

int StoneBlock::render(Camara &camara)
{
	return camara.render(this->sprite, dest_world);
}

void StoneBlock::setDestWorld(float x, float y, float width, float height)
{
	dest_world.set(x, y, width, height);
}

StoneBlock::~StoneBlock()
{
}