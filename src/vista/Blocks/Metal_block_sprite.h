#ifndef __METALBLOCKSPRITE_H__
#define __METALBLOCKSPRITE_H__
#include <string>
#include "../Sprite.h"
#include "../Rect.h"

class MetalBlockSprite : public Sprite
{
public:
  MetalBlockSprite(const Window &window);
  ~MetalBlockSprite();
  virtual int render(const Rect &dest);
  virtual void setSrc(Rect &src) override;

private:
  Rect src;
};

#endif
