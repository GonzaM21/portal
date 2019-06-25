#include "../Window.h"
#include "../Constants.h"
#include "RestingIdle_player.h"
#include "Player.h"
#include "TextureBase.h"
#include <string>
#include <iostream>

RestingIdlePlayer::RestingIdlePlayer(const Window &window, const int &direction, const int& id) : Sprite(TextureBase::getInstance(window.getRenderer())->getTexture(PLAYER_SPRITE_ID), window),
                                                                                   src(X_START_POSITION, Y_POSITION_PLAYER_RESTING_IDLE, WIDTH_PLAYER_RESTING_IDLE, HEIGHT_PLAYER_RESTING_IDLE),
                                                                                   direction(direction), id(id)
{
}

int RestingIdlePlayer::render(const Rect &dest)
{
  int response;
  if (direction == 1)
  {
    response = Sprite::render(src, dest,SDL_FLIP_NONE,0,id);
  }
  else
  {
    response = Sprite::render(src, dest, SDL_FLIP_VERTICAL, 180,id);
  }
  int x_src = src.getX();
  x_src = (x_src + WIDTH_PLAYER_RESTING_IDLE + 1) % MAX_WIDTH_RESTING_IDLE;
  src.set(x_src, Y_POSITION_PLAYER_RESTING_IDLE, WIDTH_PLAYER_RESTING_IDLE, HEIGHT_PLAYER_RESTING_IDLE);
  return response;
}

void RestingIdlePlayer::setSrc(Rect &src)
{
  this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}

RestingIdlePlayer::~RestingIdlePlayer()
{
}