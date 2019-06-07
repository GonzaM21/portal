#ifndef __ACID_H__
#define __ACID_H__
#include <string>
#include "../Rect.h"
#include "../Window.h"
#include "../Sprite.h"
#include <string>
#include "../Camara.h"

class Acid
{
public:
  Acid(const Window &window);
  ~Acid();
  int render(Camara &camara);
  void setTouched();
  void setIdle();
  void setDestWorld(float x, float y, float widht, float heigh);
  Rect getDestWorld() { return dest_world; };

private:
  Rect dest_world;
  Sprite *sprite;
  Window window;
};

#endif
