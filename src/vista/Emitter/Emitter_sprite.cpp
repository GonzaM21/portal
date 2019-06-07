#include "Emitter_sprite.h"
#include "../Constants.h"
#include "../Window.h"
#include <string>
#include <iostream>

EmitterSprite::EmitterSprite(const Window &window, const int &code, const int &state) : Sprite(BLOCK_FILENAME, window),
                                                                                        src(0, 0, 0, 0)
{
  switch (code)
  {
  case 0:
    src.set(X_START_POSITION, Y_POSITION_BLOCK_LAUNCH_UP, WIDTH_BLOCK_LAUNCH, HEIGHT_BLOCK_LAUNCH);
    break;

  case 1:
    src.set(X_START_POSITION, Y_POSITION_BLOCK_LAUNCH_RIGHT, WIDTH_BLOCK_LAUNCH, HEIGHT_BLOCK_LAUNCH);
    break;

  case 2:
    src.set(X_START_POSITION, Y_POSITION_BLOCK_LAUNCH_DOWN, WIDTH_BLOCK_LAUNCH, HEIGHT_BLOCK_LAUNCH);
    break;

  case 3:
    src.set(X_START_POSITION, Y_POSITION_BLOCK_LAUNCH_LEFT, WIDTH_BLOCK_LAUNCH, HEIGHT_BLOCK_LAUNCH);
    break;

  default:
    break;
  }
}

int EmitterSprite::render(const Rect &dest)
{
  int response = Sprite::render(src, dest);
  return response;
}

void EmitterSprite::setSrc(Rect &src)
{
  this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}

void EmitterSprite::setState(const int &state){
  this->state = state;
  //inactive->setState(state);
}

EmitterSprite::~EmitterSprite()
{
  //delete inactive;
}