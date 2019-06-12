#include "../Constants.h"
#include "../Window.h"
#include "Opening_gate.h"
#include "../Sprite.h"
#include "../Rect.h"
#include "vista/TextureBase.h"
#include <string>
#include <iostream>
#define X_POSITION 1
#define Y_POSITION 2051
#define WIDTH 193
#define HEIGHT 385

OpeningGate::OpeningGate(const Window &window, const int &code) : Sprite(TextureBase::getInstance(window.getRenderer())->getTexture(GATE_SPRITE_ID), window),
                                                                  src(X_START_POSITION, Y_POSITION_GATE_OPENING, WIDTH_GATE, HEIGHT_GATE)
{
  y_position = 0;
  switch (code)
  {
  case 1:
    y_position = Y_POSITION_GATE_OPENING_1;
    break;
  case 2:
    y_position = Y_POSITION_GATE_OPENING_2;
    break;
  case 3:
    y_position = Y_POSITION_GATE_OPENING_3;
    break;
  case 4:
    y_position = Y_POSITION_GATE_OPENING_4;
    break;
  case 5:
    y_position = Y_POSITION_GATE_OPENING_5;
    break;

  default:
    break;
  }
  this->src.set(X_START_POSITION, y_position, WIDTH_GATE, HEIGHT_GATE);
}

int OpeningGate::render(const Rect &dest)
{
  int x_src = src.getX();
  int y_src = src.getY();
  x_src = (x_src + WIDTH_GATE + 1);
  if (x_src > 10 * WIDTH_GATE + 10 && y_src == y_position)
  {
    x_src = 1;
    y_src += HEIGHT_GATE + 1;
  }
  else if (x_src > 9 * WIDTH_GATE + 9 && y_src == y_position + HEIGHT_GATE + 1)
  {
    done = true;
    x_src = 8 * WIDTH_GATE + 9;
  }
  src.set(x_src, y_src, WIDTH, HEIGHT);
  return Sprite::render(src, dest);
}

bool OpeningGate::isDone()
{
  return done;
}

void OpeningGate::restart()
{
  done = false;
  this->src.set(X_START_POSITION, y_position, WIDTH_GATE, HEIGHT_GATE);
}
void OpeningGate::setSrc(Rect &src)
{
  this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
  if (src.getX() == 8 * WIDTH_GATE + 9 && src.getY() == y_position + HEIGHT_GATE + 1)
  {
    done = true;
  }
}

OpeningGate::~OpeningGate()
{
}