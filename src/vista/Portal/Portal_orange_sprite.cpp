#include "../Window.h"
#include "../Constants.h"
#include "Portal_orange_sprite.h"
#include "TextureBase.h"
#include <string>
#include <iostream>

OrangePortal::OrangePortal(const Window &window, const int &direction) : Sprite(TextureBase::getInstance(window.getRenderer())->getTexture(PORTAL_ORANGE_SPRITE_ID), window),
                                                                         src(X_START_POSITION, Y_POSITION_PORTAL, WIDTH_PORTAL, HEIGHT_PORTAL),
                                                                         direction(direction)
{
}

int OrangePortal::render(const Rect &dest)
{
  int response = 0;
  if (direction == 1)
  {
    response = Sprite::render(src, dest);
  }
  else
  {
    response = Sprite::render(src, dest, SDL_FLIP_VERTICAL, 90);
  }
  return response;
}

void OrangePortal::setSrc(Rect &src)
{
  this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}

bool OrangePortal::isDone()
{
  return done;
}

OrangePortal::~OrangePortal()
{
}