#include "Metal_block_sprite.h"
#include "../Constants.h"
#include "../Window.h"
#include "TextureBase.h"
#include <string>
#include <iostream>

MetalBlockSprite::MetalBlockSprite(const Window &window) : Sprite(TextureBase::getInstance(window.getRenderer())->getTexture(BLOCK_SPRITE_ID), window),
                                                           src(X_START_POSITION, Y_POSITION_BLOCK_METAL, WIDTH_BLOCK_METAL, HEIGHT_BLOCK_METAL)
{
}

int MetalBlockSprite::render(const Rect &dest)
{
  int response = Sprite::render(src, dest);
  return response;
}

void MetalBlockSprite::setSrc(Rect &src)
{
  this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}

MetalBlockSprite::~MetalBlockSprite()
{
}