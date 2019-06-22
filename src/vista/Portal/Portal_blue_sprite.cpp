#include "../Window.h"
#include "../Constants.h"
#include "Portal_blue_sprite.h"
#include "TextureBase.h"
#include <string>
#include <iostream>

BluePortal::BluePortal(const Window &window, const int &direction) : Sprite(TextureBase::getInstance(window.getRenderer())->getTexture(PORTAL_BLUE_SPRITE_ID), window),
                                                                     src(X_START_POSITION, Y_POSITION_PORTAL, WIDTH_PORTAL, HEIGHT_PORTAL),
                                                                     direction(direction)
{
}

int BluePortal::render(const Rect &dest)
{
  int response = Sprite::render(src, dest, SDL_FLIP_VERTICAL, 45 * direction);
  return response;
}

void BluePortal::setSrc(Rect &src)
{
  this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}

bool BluePortal::isDone()
{
  return done;
}

void BluePortal::setDirection(const int &direction)
{
  this->direction = direction;
}

BluePortal::~BluePortal()
{
}