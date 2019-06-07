#include "Target_sprite.h"
#include "../Constants.h"
#include "../Window.h"
#include <string>
#include <iostream>

TargetSprite::TargetSprite(const Window &window, const int &state) : Sprite(TARGET_FILENAME, window),
                                                                     src(0, 0, 224, 224), state(state)
{
}

int TargetSprite::render(const Rect &dest)
{
  if (state == 1)
  {
    dest.prfloat();
    Rect dest_inactive(dest.getX() + 0.27 * dest.getWidth(), dest.getY() + 0.28 * dest.getHeight(), 0.47 * dest.getWidth(), 0.47 * dest.getHeight());
    int response = Sprite::render(src, dest_inactive);
    return response;
  }
  return 0;
}

void TargetSprite::setSrc(Rect &src)
{
  this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}

void TargetSprite::setState(const int &state)
{
  this->state = state;
}

TargetSprite::~TargetSprite()
{
}