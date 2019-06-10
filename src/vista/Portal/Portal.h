#ifndef __PORTAL_H__
#define __PORTAL_H__
#include <string>
#include "../Rect.h"
#include "../Window.h"
#include "../Camara.h"

class Portal
{
public:
  Portal(const Window &window, const int &code, const int &direction);
  ~Portal();
  int render(Camara &camara);
  void setDestWorld(float x, float y, float widht, float heigh);
  Rect getDestWorld() { return dest_world; };

private:
  Window window;
  Rect dest_world;
  Sprite *sprite;
};

#endif
