#include "../Window.h"
#include "../Constants.h"
#include "../Rect.h"
#include "../Sprite.h"
#include "Open_gate.h"
#include "TextureBase.h"
#include <string>
#include <iostream>

OpenGate::OpenGate(const Window &window, const int &code) : Sprite(TextureBase::getInstance(window.getRenderer())->getTexture(GATE_SPRITE_ID), window),
                                                            src(X_POSITION_GATE_OPEN, Y_POSITION_GATE_OPEN_1, WIDTH_GATE, HEIGHT_GATE)
{
  int y_position = 0;
  switch (code)
  {
  case 1:
    y_position = Y_POSITION_GATE_OPEN_1;
    break;
  case 2:
    y_position = Y_POSITION_GATE_OPEN_2;
    break;
  case 3:
    y_position = Y_POSITION_GATE_OPEN_3;
    break;
  case 4:
    y_position = Y_POSITION_GATE_OPEN_4;
    break;
  case 5:
    y_position = Y_POSITION_GATE_OPEN_5;
    break;

  default:
    break;
  }
  this->src.set(X_POSITION_GATE_OPEN, y_position, WIDTH_GATE, HEIGHT_GATE);
}

int OpenGate::render(const Rect &dest)
{
  return Sprite::render(src, dest);
}

void OpenGate::setSrc(Rect &src)
{
  this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}

OpenGate::~OpenGate()
{
}