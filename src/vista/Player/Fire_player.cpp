#include "../Window.h"
#include "../Constants.h"
#include "Fire_player.h"
#include "Player.h"
#include "TextureBase.h"
#include <string>
#include <iostream>
#define X_POSITION 1
#define Y_POSITION 2755
#define WIDTH 150
#define HEIGHT 200

FirePlayer::FirePlayer(const Window &window, const int &direction, const int& id) : Sprite(TextureBase::getInstance(window.getRenderer())->getTexture(PLAYER_SPRITE_ID), window),
																																		 src(X_START_POSITION, Y_POSITION_PLAYER_FIRE, WIDTH_PLAYER_FIRE, HEIGHT_PLAYER_FIRE),
																																		 done(false),
																																		 direction(direction), id(id)
{
}

int FirePlayer::render(const Rect &dest)
{
	int response;
	if (direction == 1)
	{
		response = Sprite::render(src, dest,SDL_FLIP_NONE,0,id);
	}
	else
	{
		response = Sprite::render(src, dest, SDL_FLIP_VERTICAL, 180,id);
	}
	int x_src = src.getX();
	x_src = (x_src + WIDTH_PLAYER_FIRE + 2) % 1064;
	src.set(x_src, Y_POSITION_PLAYER_FIRE, WIDTH_PLAYER_FIRE, HEIGHT_PLAYER_FIRE);
	return response;
}

void FirePlayer::setSrc(Rect &src)
{
	this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}

FirePlayer::~FirePlayer()
{
}