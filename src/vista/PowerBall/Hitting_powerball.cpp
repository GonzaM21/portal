#include "../Window.h"
#include "../Constants.h"
#include "Hitting_powerball.h"
#include "PowerBall.h"
#include "vista/TextureBase.h"
#include <string>
#include <iostream>

HittingPowerBall::HittingPowerBall(const Window &window) : Sprite(TextureBase::getInstance(window.getRenderer())->getTexture(POWERBALL_SPRITE_ID), window),
                                                           src(X_START_POSITION, Y_POSITION_POWERBALL_HITTING, WIDTH_POWERBALL_HITTING, HEIGHT_POWERBALL_HITTING)
{
}

int HittingPowerBall::render(const Rect &dest)
{
  int response = Sprite::render(src, dest);
  int x_src = src.getX();
  x_src = (x_src + WIDTH_POWERBALL_HITTING + 1) % (WIDTH_POWERBALL_HITTING * 7 + 7);
  if (x_src == 1)
    done = true;
  src.set(x_src, Y_POSITION_POWERBALL_HITTING, WIDTH_POWERBALL_HITTING, HEIGHT_POWERBALL_HITTING);
  return response;
}

void HittingPowerBall::setSrc(Rect &src)
{
  this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}

bool HittingPowerBall::isDone()
{
  return done;
}

HittingPowerBall::~HittingPowerBall()
{
}