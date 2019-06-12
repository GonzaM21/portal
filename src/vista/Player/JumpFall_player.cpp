#include "../Window.h"
#include "../Constants.h"
#include "JumpFall_player.h"
#include "Player.h"
#include "vista/TextureBase.h"
#include <string>
#include <iostream>

FallingPlayer::FallingPlayer(const Window &window, const int &direction) : Sprite(TextureBase::getInstance(window.getRenderer())->getTexture(PLAYER_SPRITE_ID), window),
                                                                           src(X_START_POSITION, Y_POSITION_PLAYER_FALLING, WIDTH_PLAYER_FALLING, HEIGHT_PLAYER_FALLING),
                                                                           direction(direction)
{
}

int FallingPlayer::render(const Rect &dest)
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
  x_src = (x_src + WIDTH_PLAYER_FALLING + 1) % MAX_WIDTH_PLAYER_FALLING;
  src.set(x_src, Y_POSITION_PLAYER_FALLING, WIDTH_PLAYER_FALLING, HEIGHT_PLAYER_FALLING);
  return response;
}

void FallingPlayer::setSrc(Rect &src)
{
  this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}

FallingPlayer::~FallingPlayer()
{
}