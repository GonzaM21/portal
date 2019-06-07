#ifndef __ROCK_H__
#define __ROCK_H__
#include <string>
#include "../Rect.h"
#include "../Window.h"
#include "../Camara.h"
#include "../Sprite.h"

class Rock
{
public:
  Rock(const Window &window);
  ~Rock();
  int render(Camara &camara);
  void setDestWorld(float x, float y, float widht, float heigh);
  Rect getDestWorld() { return dest_world; };

private:
  Rect dest_world;
  Sprite *sprite;
  Window window;
};

#endif
