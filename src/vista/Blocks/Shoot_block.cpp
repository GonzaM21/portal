#include "Shoot_block.h"
#include "../Constants.h"
#include "../Window.h"
#include <string>
#include <iostream>
#define X_POSITION 1
#define Y_POSITION 173
#define WIDTH 192
#define HEIGHT 192

ShootBlock::ShootBlock(const Window &window) : sprite(window), dest_world(0, 0, 0, 0)
{
}

int ShootBlock::render(Camara &camara)
{
	return camara.render(this->sprite, dest_world);
}

void ShootBlock::setDestWorld(float x, float y, float width, float height)
{
	dest_world.set(x, y, width, height);
}

ShootBlock::~ShootBlock()
{
}