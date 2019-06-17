#ifndef __TRIANGLEBLOCK_H__
#define __TRIANGLEBLOCK_H__
#include <string>
#include "../Sprite.h"
#include "../Rect.h"
#include "../Camara.h"
#include "Block.h"
#include "Triangle_block_sprite.h"

class TriangleBlock : public Block
{
public:
  TriangleBlock(const Window &window, const int& code);
  ~TriangleBlock();
  virtual int render(Camara &camara) override;
  virtual void setDestWorld(float x, float y, float widht, float height) override;
  virtual Rect getDestWorld() override { return dest_world; };

private:
  TriangleBlockSprite sprite;
  Rect dest_world;
};

#endif
