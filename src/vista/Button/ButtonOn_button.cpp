#include "../Window.h"
#include "../Constants.h"
#include "ButtonOn_button.h"
#include "TextureBase.h"
#include <string>
#include <iostream>

ButtonOn::ButtonOn(const Window &window) : Sprite(TextureBase::getInstance(window.getRenderer())->getTexture(BUTTON_SPRITE_ID), window),
                                           src(X_START_POSITION, Y_POSITION_BUTTON_ON, WIDTH_BUTTON_ON, HEIGHT_BUTTON_ON)
{
}

int ButtonOn::render(const Rect &dest)
{
  int response = Sprite::render(src, dest);
  return response;
}

void ButtonOn::setSrc(Rect &src)
{
  this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}

bool ButtonOn::isDone()
{
  return done;
}
ButtonOn::~ButtonOn()
{
}