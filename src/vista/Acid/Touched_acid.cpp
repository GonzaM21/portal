#include "../Window.h"
#include "../Constants.h"
#include "Touched_acid.h"
#include "../Sprite.h"
#include "../Rect.h"
#include <string>
#include <iostream>
#define ACID_FILENAME "img/acidos.png"

TouchedAcid::TouchedAcid(const Window &window) : Sprite(ACID_FILENAME, window),
                                                 src(X_START_POSITION, Y_POSITION_ACID_TOUCHED, WIDTH_ACID_TOUCHED, HEIGHT_ACID_TOUCHED)
{
}

int TouchedAcid::render(const Rect &dest)
{
  int x_src = src.getX();
  x_src = (x_src + WIDTH_ACID_TOUCHED + 1) % MAX_WIDTH_ACID_TOUCHED;
  if (x_src == 1)
    done = true;
  if (done)
    x_src = WIDTH_ACID_TOUCHED * 4 + 5;
  src.set(x_src, Y_POSITION_ACID_TOUCHED, WIDTH_ACID_TOUCHED, HEIGHT_ACID_TOUCHED);
  return Sprite::render(src, dest);
}

bool TouchedAcid::isDone()
{
  return done;
}

void TouchedAcid::setSrc(Rect &src)
{
  this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}

TouchedAcid::~TouchedAcid()
{
}