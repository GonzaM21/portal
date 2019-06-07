#include "../Window.h"
#include "../Constants.h"
#include "ButtonOff_button.h"
#include <string>
#include <iostream>

ButtonOff::ButtonOff(const Window &window) : Sprite(BUTTON_FILENAME, window),
                                             src(X_START_POSITION, Y_POSITION_BUTTON_OFF, WIDTH_BUTTON_OFF, HEIGHT_BUTTON_OFF)
{
}

int ButtonOff::render(const Rect &dest)
{
  int response = Sprite::render(src, dest);
  return response;
}

void ButtonOff::setSrc(Rect &src)
{
  this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}

bool ButtonOff::isDone()
{
  return done;
}
ButtonOff::~ButtonOff()
{
}