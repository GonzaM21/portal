#include "Metal_block.h"
#include "../Window.h"
#include "../Constants.h"
#include <string>
#include <iostream>

MetalBlock::MetalBlock(const Window &window) : sprite(window), dest_world(0, 0, 0, 0)
{
}

int MetalBlock::render(Camara &camara)
{
	return camara.render(this->sprite, dest_world);
}

void MetalBlock::setDestWorld(float x, float y, float width, float height)
{
	dest_world.set(x, y, width, height);
}

MetalBlock::~MetalBlock()
{
}