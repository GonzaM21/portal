#include "Camara.h"
#include <iostream>
#define FACTORX 0.12
#define FACTORY 0.25

Camara::Camara(const Window &window) : window(window), vision(0, 0, this->window_width, this->window_width)
{
  setWindow(0, 0, 0, 0);
}

void Camara::setWindow(float x, float y, float width, float height)
{
  window.getSize(window_width, window_height);
  vision.set(x * FACTORX * this->window_width + width, y * FACTORX * this->window_height + height, window_width, window_height);
}

int Camara::render(Sprite &sprite, Rect destWorld)
{
  Rect dest_virtual(0, 0, 0, 0);
  // destWorld.prfloat();
  convertToVirtual(destWorld, dest_virtual);
  if ((dest_virtual.getX() < vision.getX() + vision.getWidth() || dest_virtual.getX() > vision.getX() - vision.getWidth()) && (dest_virtual.getY() <= vision.getY() + vision.getHeight() || dest_virtual.getY() >= vision.getY() - vision.getHeight()))
  {
    sprite.render(dest_virtual);
  }
}

void Camara::convertToVirtual(const Rect &worldPostion, Rect &virtualPostion)
{
  float widthVirtual = worldPostion.getWidth() * FACTORX * this->window_width;
  float heightVirtual = worldPostion.getHeight() * FACTORX * this->window_height;
  float xVirtual = worldPostion.getX() * FACTORX * this->window_width + this->window_width 
  / 2 + widthVirtual / 2 - vision.getX();
  float yVirtual = worldPostion.getY() * FACTORX * this->window_height + this->window_height 
  / 2 + heightVirtual / 2 - vision.getY();
  virtualPostion.set(xVirtual, yVirtual, widthVirtual, heightVirtual);
}

Camara::~Camara()
{
}