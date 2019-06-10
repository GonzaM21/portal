#ifndef __SHOOTBLOCK_H__
#define __SHOOTBLOCK_H__
#include <string>
#include "../Sprite.h"
#include "../Rect.h"
#include "../Camara.h"
#include "Block.h"
#include "Shoot_block_sprite.h"

class ShootBlock : public Block
{
public:
	ShootBlock(const Window &window);
	~ShootBlock();
	virtual int render(Camara &camara) override;
	virtual void setDestWorld(float x, float y, float widht, float height) override;
	virtual Rect getDestWorld() override { return dest_world; };

private:
	ShootBlockSprite sprite;
	Rect dest_world;
};

#endif
