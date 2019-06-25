#include "../Window.h"
#include "../Constants.h"
#include "Idle_acid.h"
#include "../Sprite.h"
#include "../Rect.h"
#include "TextureBase.h"
#include <string>
#include <iostream>

IdleAcid::IdleAcid(const Window &window) : Sprite(TextureBase::getInstance(window.getRenderer())->getTexture(ACID_SPRITE_ID), window),
																					 src(X_START_POSITION, Y_POSITION_ACID_IDLE, WIDTH_ACID_IDLE, HEIGHT_ACID_IDLE)
{
}

int IdleAcid::render(const Rect &dest)
{
	int x_src = src.getX();
	x_src = (x_src + WIDTH_ACID_IDLE + 1) % 2408;
	src.set(x_src, Y_POSITION_ACID_IDLE, WIDTH_ACID_IDLE, HEIGHT_ACID_IDLE);
	return Sprite::render(src, dest);
}

void IdleAcid::setSrc(Rect &src)
{
	this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}

IdleAcid::~IdleAcid()
{
}