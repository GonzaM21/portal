#ifndef __METALBLOCK_H__
#define __METALBLOCK_H__
#include <string>
#include "../Sprite.h"
#include "../Rect.h"
#include "../Camara.h"
#include "Block.h"
#include "Metal_block_sprite.h"

class MetalBlock : public Block
{
public:
	MetalBlock(const Window &window);
	~MetalBlock();
	virtual int render(Camara &camara) override;
	virtual void setDestWorld(float x, float y, float widht, float height) override;
	virtual Rect getDestWorld() override { return dest_world; };

private:
	Rect dest_world;
	MetalBlockSprite sprite;
};

#endif
