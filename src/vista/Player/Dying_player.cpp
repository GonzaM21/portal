#include "../Window.h"
#include "Dying_player.h"
#include "Player.h"
#include "../Constants.h"
#include <string>
#include <iostream>

DyingPlayer::DyingPlayer(const Window &window, const int &direction) : Sprite(PLAYER_FILENAME, window),
                                                                       src(X_START_POSITION, Y_POSITION_PLAYER_DYING, WIDTH_PLAYER_DYING, HEIGHT_PLAYER_DYING),
                                                                       done(false), direction(direction)
{
}

int DyingPlayer::render(const Rect &dest)
{
  int response;
  if (done)
  {
    return -1;
  }
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
  x_src = (x_src + WIDTH_PLAYER_DYING + 1) % (MAX_WIDTH_PLAYER_DYING);
  if (x_src == 1)
  {
    y_src = (y_src + HEIGHT_PLAYER_DYING + 2) % (8 * HEIGHT_PLAYER_DYING + 16 + Y_POSITION_PLAYER_DYING);
  }
  if (y_src == 0)
  {
    y_src = Y_POSITION_PLAYER_DYING;
    done = true;
  }
  src.set(x_src, y_src, WIDTH_PLAYER_DYING, HEIGHT_PLAYER_DYING);
  return response;
}

void DyingPlayer::setSrc(Rect &src)
{
  src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}

bool DyingPlayer::isDone()
{
  return done;
}

DyingPlayer::~DyingPlayer()
{
}