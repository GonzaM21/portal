#include "Shoot_block_sprite.h"
#include "../Constants.h"
#include "../Window.h"
#include "TextureBase.h"
#include <string>
#include <iostream>

ShootBlockSprite::ShootBlockSprite(const Window &window) : Sprite(TextureBase::getInstance(window.getRenderer())->getTexture(BLOCK_SPRITE_ID), window),
                                                           src(X_START_POSITION, Y_POSITION_BLOCK_SHOOT, WIDTH_BLOCK_SHOOT, HEIGHT_BLOCK_SHOOT)
{
}

int ShootBlockSprite::render(const Rect &dest)
{
  int response = Sprite::render(src, dest);
  return response;
}

void ShootBlockSprite::setSrc(Rect &src)
{
  this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}

ShootBlockSprite::~ShootBlockSprite()
{
}