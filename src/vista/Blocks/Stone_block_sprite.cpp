#include "Stone_block_sprite.h"
#include "../Window.h"
#include "../Constants.h"
#include <string>
#include <iostream>

StoneBlockSprite::StoneBlockSprite(const Window &window) : Sprite(BLOCK_FILENAME, window),
                                                           src(X_START_POSITION, Y_POSITION_BLOCK_STONE, WIDTH_BLOCK_STONE, HEIGHT_BLOCK_STONE)
{
}

int StoneBlockSprite::render(const Rect &dest)
{
  int response = Sprite::render(src, dest);
  return response;
}

void StoneBlockSprite::setSrc(Rect &src)
{
  this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}

StoneBlockSprite::~StoneBlockSprite()
{
}