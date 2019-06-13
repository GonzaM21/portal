#include "../Window.h"
#include "../Constants.h"
#include "Closed_gate.h"
#include "../Sprite.h"
#include "../Rect.h"
#include "vista/TextureBase.h"
#include <string>
#include <iostream>

ClosedGate::ClosedGate(const Window &window, const int &code) : Sprite(TextureBase::getInstance(window.getRenderer())->getTexture(GATE_SPRITE_ID), window),
                                                                src(X_START_POSITION, Y_POSITION_GATE_CLOSED_1, WIDTH_GATE, HEIGHT_GATE)
{
  std::cout << code << std::endl;
  y_position = 0;
  switch (code)
  {
  case 1:
    y_position = Y_POSITION_GATE_CLOSED_1;
    break;
  case 2:
    y_position = Y_POSITION_GATE_CLOSED_2;
    break;
  case 3:
    y_position = Y_POSITION_GATE_CLOSED_3;
    break;
  case 4:
    y_position = Y_POSITION_GATE_CLOSED_4;
    break;
  case 5:
    y_position = Y_POSITION_GATE_CLOSED_5;
    break;

  default:
    break;
  }
  this->src.set(X_START_POSITION, y_position, WIDTH_GATE, HEIGHT_GATE);
}

int ClosedGate::render(const Rect &dest)
{
  return Sprite::render(src, dest);
}

void ClosedGate::setSrc(Rect &src)
{
  this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}

ClosedGate::~ClosedGate()
{
}