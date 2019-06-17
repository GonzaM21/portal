
#include "../Window.h"
#include "../Constants.h"
#include "Idle_player.h"
#include "TextureBase.h"
#include <string>
#include <iostream>
#define X_POSITION 1
#define Y_POSITION 2755
#define WIDTH 150
#define HEIGHT 200

IdlePlayer::IdlePlayer(const Window &window, const int &direction) : 
	Sprite(TextureBase::getInstance(window.getRenderer())->getTexture(PLAYER_SPRITE_ID), window),src(X_START_POSITION, Y_POSITION_PLAYER_IDLE, 
	WIDTH_PLAYER_IDLE, HEIGHT_PLAYER_IDLE) ,direction(direction)
{
}

int IdlePlayer::render(const Rect &dest)
{
	int response;
	if (direction == 1)
	{
		response = Sprite::render(src, dest,SDL_FLIP_NONE,0,1);
	}
	else
	{
		response = Sprite::render(src, dest, SDL_FLIP_VERTICAL, 180,1);
	}
	int x_src = src.getX();
	x_src = (x_src + WIDTH_PLAYER_IDLE + 2) % 1064;
	src.set(x_src, Y_POSITION_PLAYER_IDLE, WIDTH_PLAYER_IDLE, HEIGHT_PLAYER_IDLE);
	return response;
}

void IdlePlayer::setSrc(Rect &src)
{
	this->src.set(src.getX(), src.getY(), src.getWidth(), src.getHeight());
}
IdlePlayer::~IdlePlayer()
{
}