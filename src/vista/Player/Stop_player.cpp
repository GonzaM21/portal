#include "../Window.h"
#include "../Constants.h"
#include "Stop_player.h"
#include "TextureBase.h"
#include "Player.h"
#include <string>
#include <iostream>

StopPlayer::StopPlayer(const Window &window, const int &direction, const int& id) : Sprite(TextureBase::getInstance(window.getRenderer())->getTexture(PLAYER_SPRITE_ID), window),
                                                                     src(X_START_POSITION, Y_POSITION_PLAYER_STOP, WIDTH_PLAYER_STOP, HEIGHT_PLAYER_STOP),
                                                                     done(false),
                                                                     direction(direction), id(id)
{
}

int StopPlayer::render(const Rect &dest)
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
  int y_src = src.getY();
  x_src = (x_src + WIDTH_PLAYER_STOP + 1);
  if (x_src > MAX_WIDTH_PLAYER_STOP && y_src == Y_POSITION_PLAYER_STOP)
  {
    x_src = 1;
    y_src += HEIGHT_PLAYER_STOP + 2;
  }
  else if (x_src > 2 * WIDTH_PLAYER_STOP + 2 && y_src == Y_POSITION_PLAYER_STOP + HEIGHT_PLAYER_STOP + 2)
  {
    x_src = 1;
    y_src = Y_POSITION_PLAYER_STOP;
    done = true;
  }
  src.set(x_src, y_src, WIDTH_PLAYER_STOP, HEIGHT_PLAYER_STOP);
  return response;
}

bool StopPlayer::isDone()
{
  return done;
}

void StopPlayer::setSrc(Rect &src)
{
  this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}

StopPlayer::~StopPlayer()
{ 
}