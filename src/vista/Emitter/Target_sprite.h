#ifndef __TARGETSPRITE_H__
#define __TARGETSPRITE_H__
#include <string>
#include "../Sprite.h"
#include "../Rect.h"

class TargetSprite : public Sprite
{
public:
  TargetSprite(const Window &window, const int &state);
  ~TargetSprite();
  virtual int render(const Rect &dest);
  virtual void setSrc(Rect &src) override;
  void setState(const int &state);

private: 
  Rect src;
  int state;
};

#endif
