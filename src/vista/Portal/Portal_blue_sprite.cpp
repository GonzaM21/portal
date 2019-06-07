#include "../Window.h"
#include "../Constants.h"
#include "Portal_blue_sprite.h"
#include <string>
#include <iostream>

BluePortal::BluePortal(const Window &window, const int &direction) : Sprite(PORTAL_BLUE_FILENAME, window),
                                                                     src(X_START_POSITION, Y_POSITION_PORTAL, WIDTH_PORTAL, HEIGHT_PORTAL),
                                                                     direction(direction)
{
}

int BluePortal::render(const Rect &dest)
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

void BluePortal::setSrc(Rect &src)
{
  this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}

bool BluePortal::isDone()
{
  return done;
}

BluePortal::~BluePortal()
{
}