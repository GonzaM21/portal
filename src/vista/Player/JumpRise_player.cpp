#include "../Window.h"
#include "../Constants.h"
#include "JumpRise_player.h"
#include "TextureBase.h"
#include "Player.h"
#include <string>
#include <iostream>

RisingPlayer::RisingPlayer(const Window &window, const int &direction) : Sprite(TextureBase::getInstance(window.getRenderer())->getTexture(PLAYER_SPRITE_ID), window),
                                                                         src(X_START_POSITION, Y_POSITION_PLAYER_RISING, WIDTH_PLAYER_RISING, HEIGHT_PLAYER_RISING),
                                                                         direction(direction)
{
}

int RisingPlayer::render(const Rect &dest)
{
  int response;
  if (direction == 1)
  {
    response = Sprite::render(src, dest);
  }
  else
  {
    response = Sprite::render(src, dest, SDL_FLIP_VERTICAL, 180);
  }
  int x_src = src.getX();
  x_src = (x_src + WIDTH_PLAYER_RISING + 1) % MAX_WIDTH_PLAYER_RISING;
  src.set(x_src, Y_POSITION_PLAYER_RISING, WIDTH_PLAYER_RISING, HEIGHT_PLAYER_RISING);
  return response;
}

void RisingPlayer::setSrc(Rect &src)
{
  this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}

RisingPlayer::~RisingPlayer()
{
}