#ifndef __STONEBLOCKSPRITE_H__
#define __STONEBLOCKSPRITE_H__
#include <string>
#include "../Sprite.h"
#include "../Rect.h"

class StoneBlockSprite : public Sprite
{
public:
  StoneBlockSprite(const Window &window);
  ~StoneBlockSprite();
  virtual int render(const Rect &dest);
  virtual void setSrc(Rect &src) override;

private:
  Rect src;
};

#endif
