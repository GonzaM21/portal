#include "../Window.h"
#include "../Constants.h"
#include "Paw_powerball.h"
#include "PowerBall.h"
#include "TextureBase.h"
#include <string>
#include <iostream>

PawPowerBall::PawPowerBall(const Window &window) : Sprite(TextureBase::getInstance(window.getRenderer())->getTexture(POWERBALL_SPRITE_ID), window),
                                                   src(X_START_POSITION, Y_POSITION_POWERBALL_PAW, WIDTH_POWERBALL_PAW, HEIGHT_POWERBALL_PAW)
{
}

int PawPowerBall::render(const Rect &dest)
{
  int response = Sprite::render(src, dest);
  int x_src = src.getX();
  x_src = (x_src + WIDTH_POWERBALL_PAW + 1) % (WIDTH_POWERBALL_PAW * 5 + 5);
  if (x_src == 1)
  {
    done = true;
  }
  src.set(x_src, Y_POSITION_POWERBALL_PAW, WIDTH_POWERBALL_PAW, HEIGHT_POWERBALL_PAW);
  return response;
}

void PawPowerBall::setSrc(Rect &src)
{
  this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}

bool PawPowerBall::isDone()
{
  return done;
}

PawPowerBall::~PawPowerBall()
{
}