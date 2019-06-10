
#include "../Window.h"
#include "../Constants.h"
#include "Running_player.h"
#include "Player.h"
#include <string>
#include <iostream>

RunningPlayer::RunningPlayer(const Window &window, const int &direction) : Sprite(PLAYER_FILENAME, window),
                                                                           src(X_START_POSITION, Y_POSITION_PLAYER_RUNNING, WIDTH_PLAYER_RUNNING, HEIGHT_PLAYER_RUNNING),
                                                                           direction(direction)
{
}

int RunningPlayer::render(const Rect &dest)
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
  x_src = (x_src + WIDTH_PLAYER_RUNNING + 1);
  if (x_src > MAX_WIDTH_PLAYER_RUNNING && y_src == Y_POSITION_PLAYER_RUNNING)
  {
    x_src = 1;
    y_src += HEIGHT_PLAYER_RUNNING + 1;
  }
  else if (x_src > 4 * WIDTH_PLAYER_RUNNING + 4 && y_src == Y_POSITION_PLAYER_RUNNING + HEIGHT_PLAYER_RUNNING + 1)
  {
    x_src = 1;
    y_src = Y_POSITION_PLAYER_RUNNING;
  }
  src.set(x_src, y_src, WIDTH_PLAYER_RUNNING, HEIGHT_PLAYER_RUNNING);
  return response;
}

void RunningPlayer::setSrc(Rect &src)
{
  this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}

RunningPlayer::~RunningPlayer()
{
}