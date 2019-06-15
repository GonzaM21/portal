#include "../Window.h"
#include "../Constants.h"
#include "RunningShoot_player.h"
#include "TextureBase.h"
#include "Player.h"
#include <string>
#include <iostream>

RunningShootPlayer::RunningShootPlayer(const Window &window, const int &direction) : Sprite(TextureBase::getInstance(window.getRenderer())->getTexture(PLAYER_SPRITE_ID), window),
                                                                                     src(X_START_POSITION, Y_POSITION_PLAYER_RUNNING_SHOOT, WIDTH_PLAYER_RUNNING_SHOOT, HEIGHT_PLAYER_RUNNING_SHOOT),
                                                                                     direction(direction)
{
}

int RunningShootPlayer::render(const Rect &dest)
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
  int y_src = src.getY();
  x_src = (x_src + WIDTH_PLAYER_RUNNING_SHOOT + 1);
  if (x_src > MAX_WIDTH_PLAYER_RUNNING_SHOOT && y_src == Y_POSITION_PLAYER_RUNNING_SHOOT)
  {
    x_src = 1;
    y_src += HEIGHT_PLAYER_RUNNING_SHOOT + 2;
  }
  else if (x_src > 4 * WIDTH_PLAYER_RUNNING_SHOOT + 4 && y_src == Y_POSITION_PLAYER_RUNNING_SHOOT + HEIGHT_PLAYER_RUNNING_SHOOT + 2)
  {
    x_src = 1;
    y_src = Y_POSITION_PLAYER_RUNNING_SHOOT;
  }
  src.set(x_src, y_src, WIDTH_PLAYER_RUNNING_SHOOT, HEIGHT_PLAYER_RUNNING_SHOOT);
  return response;
}

void RunningShootPlayer::setSrc(Rect &src)
{
  this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}

RunningShootPlayer::~RunningShootPlayer()
{
}