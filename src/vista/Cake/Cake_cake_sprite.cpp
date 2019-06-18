#include "../Window.h"
#include "../Constants.h"
#include "Cake_cake_sprite.h"
#include "TextureBase.h"
#include <string>
#include <iostream>
#include <random>

CakeSprite::CakeSprite(const Window &window) : Sprite(TextureBase::getInstance(window.getRenderer())->getTexture(CAKE_SPRITE_ID),window),
                                               src(X_START_POSITION, Y_POSITION_CAKE, WIDTH_CAKE, HEIGHT_CAKE)
{  
  this->src.set(X_START_POSITION, Y_POSITION_CAKE,WIDTH_CAKE, HEIGHT_CAKE);
}

int CakeSprite::render(const Rect &dest)
{
  int response = Sprite::render(src, dest);
  return response;
}

void CakeSprite::setSrc(Rect &src)
{
  this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}