#ifndef __ENERGYBARRIER_H__
#define __ENERGYBARRIER_H__
#include <string>
#include "../Rect.h"
#include "../Window.h"
#include "../Sprite.h"
#include "../Camara.h"
#include <unordered_map>

class EnergyBarrier
{
public:
  EnergyBarrier(const Window &window, const int &code);
  ~EnergyBarrier();
  int render(Camara &camara);
  void setDestWorld(float x, float y, float widht, float heigh);
  Rect getDestWorld() { return dest_world; };

private:
  Rect dest_world;
  Sprite *sprite;
};

#endif
