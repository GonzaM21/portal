#include "../Window.h"
#include "../Constants.h"
#include "EnergyBarrier_sprite.h"
#include "../Sprite.h"
#include "../Rect.h"
#include "TextureBase.h"
#include <string>
#include <iostream>

EnergyBarrierSprite::EnergyBarrierSprite(const Window &window, const int &code) : Sprite(TextureBase::getInstance(window.getRenderer())->getTexture(ENERGY_BARRIER_SPRITE_ID), window),
                                                                src(X_START_POSITION, Y_POSITION_ENERGY_BARRIER, WIDTH_ENERGY_BARRIER, HEIGHT_ENERGY_BARRIER),
                                                                code(code)
{
}

int EnergyBarrierSprite::render(const Rect &dest)
{ 
  int response = 0;
  if (code == 1)
  {
    response = Sprite::render(src, dest);
  } else {
    response = Sprite::render(src, dest, SDL_FLIP_HORIZONTAL, 90);
  }
  return response; 
}

void EnergyBarrierSprite::setSrc(Rect &src)
{
  this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}

EnergyBarrierSprite::~EnergyBarrierSprite()
{
}