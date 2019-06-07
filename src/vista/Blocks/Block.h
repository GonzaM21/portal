#ifndef __BLOCK_H__
#define __BLOCK_H__
#include <string>
#include "../Rect.h"
#include "../Window.h"
#include "../Camara.h"
#include "../Sprite.h"

class Block
{
public:
  Block(){};
  ~Block(){};
  virtual int render(Camara &camara) = 0;
  virtual void setDestWorld(float x, float y, float widht, float heigh) = 0;
  virtual Rect getDestWorld() = 0;

private:
};

#endif
