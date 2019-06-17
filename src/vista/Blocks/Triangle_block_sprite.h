#ifndef __TRIANGLEBLOCKSPRITE_H__
#define __TRIANGLEBLOCKSPRITE_H__
#include <string>
#include "../Sprite.h"
#include "../Rect.h"

class TriangleBlockSprite : public Sprite
{
public:
  TriangleBlockSprite(const Window &window, const int& code);
  ~TriangleBlockSprite();
  virtual int render(const Rect &dest);
  virtual void setSrc(Rect &src) override;

private:
  Rect src;
  int code;
};

#endif
