#ifndef __SHOOTBLOCKSPRITE_H__
#define __SHOOTBLOCKSPRITE_H__
#include <string>
#include "../Sprite.h"
#include "../Rect.h"

class ShootBlockSprite : public Sprite
{
public:
  ShootBlockSprite(const Window &window);
  ~ShootBlockSprite();
  virtual int render(const Rect &dest);
  virtual void setSrc(Rect &src) override;

private:
  Rect src;
};

#endif
