#ifndef CAKE_H
#define CAKE_H
#include <string>
#include "../Rect.h"
#include "../Window.h"
#include "../Camara.h"
#include "../Sprite.h"

class Cake
{
public:
  Cake(const Window &window);
  ~Cake();
  int render(Camara &camara);
  void setDestWorld(float x, float y, float widht, float heigh);
  Rect getDestWorld() { return dest_world; };

private:
  Window window;
  Rect dest_world;
  Sprite *sprite;
};

#endif
