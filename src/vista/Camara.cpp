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
  vision.set(x, y, window_width * FACTORX, window_height * FACTORX);
}

int Camara::render(Sprite &sprite, Rect destWorld) {
  Rect dest_virtual(0, 0, 0, 0);
  convertToVirtual(destWorld, dest_virtual);
  if ((dest_virtual.getX() <= this->window_width + 100 && dest_virtual.getX() >= -100) && (dest_virtual.getY() <= this->window_height + 100  && dest_virtual.getY() >= -100))
  {
    return sprite.render(dest_virtual);
  }
  return -1;
}

void Camara::convertToVirtual(const Rect &worldPostion, Rect &virtualPostion) {
  float widthVirtual = worldPostion.getWidth() * FACTORX * this->window_width;
  float heightVirtual = worldPostion.getHeight() * FACTORX * this->window_height;
  float xVirtual = ( worldPostion.getX() - vision.getX()) * FACTORX * this->window_width + this->window_width / 2 - widthVirtual / 2;
  float yVirtual = (worldPostion.getY() - vision.getY()) * FACTORX * this->window_height + this->window_height / 2 - heightVirtual / 2;
  virtualPostion.set(xVirtual, yVirtual, widthVirtual, heightVirtual);
}

void Camara::convertToWorld(Rect &worldPostion, const Rect &virtualPostion) {
  float widthWorld = virtualPostion.getWidth() / (FACTORX * this->window_width);
  float heightWorld = virtualPostion.getHeight() / (FACTORX * this->window_height);
  float xWorld = (virtualPostion.getX() - this->window_width / 2 + widthWorld / 2) / (FACTORX * this->window_width) + vision.getX();
  float yWorld = (virtualPostion.getY() - this->window_height / 2 + heightWorld / 2) / (FACTORX * this->window_height) + vision.getY();
  worldPostion.set(xWorld, yWorld, widthWorld, heightWorld);
}

Camara::~Camara()
{
}