#ifndef __ROCKSPRITE_H__
#define __ROCKSPRITE_H__
#include <string>
#include <SDL2/SDL_image.h>
#include "../Sprite.h"
#include "../Rect.h"

/**
 * Clase que hereda de sprite, y este es el sprite de las rocas
*/
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
};

#endif
