#ifndef __ROCKSPRITE_H__
#define __ROCKSPRITE_H__
#include <string>
#include <SDL2/SDL_image.h>
#include "../Sprite.h"
#include "../Rect.h"

/*Clase abstracta State, 
es el estado de la puerta, 
aqui aplicando un patrron state */
class RockSprite : public Sprite
{
public:
  RockSprite(const Window &window);
  ~RockSprite();
  virtual int render(const Rect &dest);
  virtual void setSrc(Rect &src) override;

private:
  Rect src;
  bool done = false;
  int direction;
};

#endif
