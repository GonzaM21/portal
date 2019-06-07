#include "../Window.h"
#include "../Constants.h"
#include "Flying_powerball.h"
#include "PowerBall.h"
#include <string>
#include <iostream>

FlyingPowerBall::FlyingPowerBall(const Window &window) : Sprite(POWERBALL_FILENAME, window),
                                                         src(X_START_POSITION, Y_POSITION_POWERBALL_FLYING, WIDTH_POWERBALL_FLYING, HEIGHT_POWERBALL_FLYING)
{
}

int FlyingPowerBall::render(const Rect &dest)
{
  int response = Sprite::render(src, dest);
  int x_src = src.getX();
  x_src = (x_src + WIDTH_POWERBALL_FLYING + 2) % (WIDTH_POWERBALL_FLYING * 3 + 6);
  src.set(x_src, Y_POSITION_POWERBALL_FLYING, WIDTH_POWERBALL_FLYING, HEIGHT_POWERBALL_FLYING);
  return response;
}

void FlyingPowerBall::setSrc(Rect &src)
{
  this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}

bool FlyingPowerBall::isDone()
{
  return done;
}
FlyingPowerBall::~FlyingPowerBall()
{
}