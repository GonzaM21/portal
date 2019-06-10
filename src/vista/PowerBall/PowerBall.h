#ifndef __POWERBALL_H__
#define __POWERBALL_H__
#include <string>
#include "../Rect.h"
#include "../Window.h"
// #include "../Sprite.h"
#include "../Camara.h"

class PowerBall
{
public:
  PowerBall(const Window &window, const int &state);
  ~PowerBall();
  int render(Camara &camara);
  void setFlying();
  void setHitting();
  void setPaw();
  bool hitted();
  bool isDone();
  void setDestWorld(float x, float y, float widht, float heigh);
  Rect getDestWorld() { return dest_world; };

private:
  Window window;
  Rect dest_world;
  Sprite *sprite;
};

#endif
