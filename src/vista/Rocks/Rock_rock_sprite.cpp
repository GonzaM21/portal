#include "../Window.h"
#include "../Constants.h"
#include "Rock_rock_sprite.h"
#include <string>
#include <iostream>
#include <random>

RockSprite::RockSprite(const Window &window) : Sprite(ROCK_FILENAME, window),
                                               src(X_START_POSITION, Y_POSITION_ROCK, WIDTH_ROCK, HEIGHT_ROCK)
{  
  float num_rock = std::rand() % (7) ;
  float new_x = X_START_POSITION + num_rock * WIDTH_ROCK + num_rock;
  this->src.set(new_x, Y_POSITION_ROCK , WIDTH_ROCK, HEIGHT_ROCK);
}

int RockSprite::render(const Rect &dest)
{
  int response = response = Sprite::render(src, dest);
  return response;
}

void RockSprite::setSrc(Rect &src)
{
  this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}

RockSprite::~RockSprite()
{
}