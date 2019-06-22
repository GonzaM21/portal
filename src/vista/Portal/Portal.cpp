#include "Portal.h"
#include "Window.h"
#include "Portal_blue_sprite.h"
#include "Portal_orange_sprite.h"
#include "Constants.h"
#include <string>
#include <iostream>
#include <typeinfo>

Portal::Portal(const Window &window, const int &code, const int &direction) : window(window),
                                                                              dest_world(0, 0, WIDTH_PORTAL, HEIGHT_PORTAL)
{
  switch (code)
  {
  case 1:
    this->sprite = new BluePortal(window, direction);
    break;

  case 2:
    this->sprite = new OrangePortal(window, direction);
    break;

  default:
    break;
  }
}

int Portal::render(Camara &camara)
{
  return camara.render(*sprite, dest_world);
}

void Portal::setDestWorld(float x, float y, float width, float height)
{
  dest_world.set(x, y, width, height);
}

void Portal::setState(const int &direction)
{
  this->sprite->setDirection(direction);
}

Portal::~Portal()
{
  delete this->sprite;
}