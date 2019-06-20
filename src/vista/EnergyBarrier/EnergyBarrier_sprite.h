#ifndef __ENERGYBARRIERSPRITE_H__
#define __ENERGYBARRIERSPRITE_H__
#include <string>
#include <SDL2/SDL_image.h>
#include "../Sprite.h"
#include "../Rect.h"

/*Clase abstracta State, 
es el estado de la puerta, 
aqui aplicando un patrron state */
class EnergyBarrierSprite : public Sprite
{
public:
  EnergyBarrierSprite(const Window &window, const int &code);
  ~EnergyBarrierSprite();
  virtual int render(const Rect &dest);
  virtual void setSrc(Rect &src) override;
  virtual Rect getSrc() override { return src; };

private:
  Rect src;
  int code;
};

#endif
