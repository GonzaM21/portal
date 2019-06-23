#include "Triangle_block_sprite.h"
#include "../Window.h"
#include "../Constants.h"
#include "TextureBase.h"
#include <string>
#include <iostream>

TriangleBlockSprite::TriangleBlockSprite(const Window &window,const int& code) : Sprite(TextureBase::getInstance(window.getRenderer())->getTexture(BLOCK_SPRITE_ID), window),
                                                           src(196, Y_POSITION_BLOCK_METAL, WIDTH_BLOCK_METAL, HEIGHT_BLOCK_METAL),
                                                           code(code)
{
}

int TriangleBlockSprite::render(const Rect &dest)
{
  //std::cout << code;
  int response = 0;
  switch (code)
  {
  case 0:
    response = Sprite::render(src, dest);
    break;
  
  case 1:
    response = Sprite::render(src, dest, SDL_FLIP_VERTICAL, 180);
    break;

  case 2:
    response = Sprite::render(src, dest, SDL_FLIP_HORIZONTAL,-90);
    break;

  case 3:
    response = Sprite::render(src, dest, SDL_FLIP_HORIZONTAL, -180);
    break;
  } 
  
  return response;
}

void TriangleBlockSprite::setSrc(Rect &src)
{
  this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}

TriangleBlockSprite::~TriangleBlockSprite()
{
}