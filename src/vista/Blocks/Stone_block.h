#ifndef __STONEBLOCK_H__
#define __STONEBLOCK_H__
#include <string>
#include "../Sprite.h"
#include "../Rect.h"
#include "../Camara.h"
#include "Block.h"
#include "Stone_block_sprite.h"

class StoneBlock : public Block
{
public:
	StoneBlock(const Window &window);
	~StoneBlock();
	virtual int render(Camara &camara) override;
	virtual void setDestWorld(float x, float y, float widht, float height) override;
	virtual Rect getDestWorld() override { return dest_world; };

private:
	StoneBlockSprite sprite;
	Rect dest_world;
};

#endif
