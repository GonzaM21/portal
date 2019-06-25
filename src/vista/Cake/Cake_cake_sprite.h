#ifndef __ROCKSPRITE_H__
#define __ROCKSPRITE_H__
#include <string>
#include <SDL2/SDL_image.h>
#include "../Sprite.h"
#include "../Rect.h"


class CakeSprite : public Sprite
{
public:
  CakeSprite(const Window &window);
  ~CakeSprite() = default;
  virtual int render(const Rect &dest);
  virtual void setSrc(Rect &src) override;

private:
  Rect src;
  bool done = false;
};

#endif
