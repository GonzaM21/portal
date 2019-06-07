#include "../Window.h"
#include "../Constants.h"
#include "Closing_gate.h"
#include "../Sprite.h"
#include "../Rect.h"

#include <string>
#include <iostream>
#define X_POSITION 1
#define Y_POSITION 2051

ClosingGate::ClosingGate(const Window &window, const int &code) : Sprite(GATE_FILENAME, window),
                                                                  src(X_POSITION_GATE_OPEN, Y_POSITION_GATE_OPEN_1, WIDTH_GATE, HEIGHT_GATE)
{
  y_position = 0;
  switch (code)
  {
  case 1:
    y_position = Y_POSITION_GATE_OPEN_1;
    y_position_gate_closed = Y_POSITION_GATE_CLOSED_1;
    break;
  case 2:
    y_position = Y_POSITION_GATE_OPEN_2;
    y_position_gate_closed = Y_POSITION_GATE_CLOSED_2;
    break;
  case 3:
    y_position = Y_POSITION_GATE_OPEN_3;
    y_position_gate_closed = Y_POSITION_GATE_CLOSED_3;
    break;
  case 4:
    y_position = Y_POSITION_GATE_OPEN_4;
    y_position_gate_closed = Y_POSITION_GATE_CLOSED_4;
    break;
  case 5:
    y_position = Y_POSITION_GATE_OPEN_5;
    y_position_gate_closed = Y_POSITION_GATE_CLOSED_5;
    break;

  default:
    break;
  }
  this->src.set(X_POSITION_GATE_OPEN, y_position, WIDTH_GATE, HEIGHT_GATE);
}

int ClosingGate::render(const Rect &dest)
{
  int x_src = src.getX();
  int y_src = src.getY();
  if (x_src - WIDTH_GATE - 1 > 1)
  {
    x_src = x_src - WIDTH_GATE - 1;
  }
  else if (x_src - WIDTH_GATE - 1 == 1)
  {
    if (y_src == y_position_gate_closed)
    {
      done = true;
      x_src = x_src - WIDTH_GATE - 1;
    }
    else
    {
      x_src = (9 * WIDTH_GATE) + 10;
      y_src = y_position_gate_closed;
    }
  }
  else if (x_src == 1 && y_src != y_position_gate_closed)
  {
    x_src = (9 * WIDTH_GATE) + 10;
    y_src = y_position_gate_closed;
  }
  src.set(x_src, y_src, WIDTH_GATE, HEIGHT_GATE);
  return Sprite::render(src, dest);
}

bool ClosingGate::isDone()
{
  return done;
}

void ClosingGate::restart()
{
  done = false;
  this->src.set(X_POSITION_GATE_OPEN, y_position, WIDTH_GATE, HEIGHT_GATE);
}

void ClosingGate::setSrc(Rect &src)
{
  this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
  if (src.getX() == 1 && src.getY() == y_position_gate_closed)
  {
    done = true;
  }
}

ClosingGate::~ClosingGate()
{
}