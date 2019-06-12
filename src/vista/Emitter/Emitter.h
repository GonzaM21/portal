#ifndef __EMITTER_H__
#define __EMITTER_H__
#include <string>
#include "../Sprite.h"
#include "../Rect.h"
#include "Emitter_sprite.h"
#include "vista/Emitter/Target_sprite.h"
#include "../Camara.h"

class Emitter
{
public:
	Emitter(const Window &window, const int &code, const int &state);
	~Emitter();
	int render(Camara &camara);
	void setDestWorld(float x, float y, float widht, float height);
	Rect getDestWorld() { return dest_world; };
	void setState(const int& state);

private:
	Rect dest_world;
	EmitterSprite sprite;
	TargetSprite* inactive;
};

#endif
