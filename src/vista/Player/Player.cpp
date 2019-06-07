#include "Player.h"
#include "../Window.h"
#include "Idle_player.h"
#include "RestingIdle_player.h"
#include "Stop_player.h"
#include "Dying_player.h"
#include "Running_player.h"
#include "Dancing_player.h"
#include "RunningShoot_player.h"
#include "../Constants.h"
#include "../Camara.h"
#include <string>
#include <iostream>
#include <functional>

Player::Player(const Window &window, const int &direction) : direction(direction),
																														 window(window), dest_world(0, 0, 0.5, 1.6)
{
	this->changeState[0] = &Player::setIdle;
	this->changeState[1] = &Player::setRestIdle;
	this->changeState[2] = &Player::setRunning;
	this->changeState[3] = &Player::setDancing;
	this->changeState[4] = &Player::setDying;
	this->changeState[5] = &Player::setRunningShooting;
	this->changeState[6] = &Player::setStop;
	this->states[0] = new IdlePlayer(window, direction);
	this->states[1] = new RestingIdlePlayer(window, direction);
	this->states[2] = new RunningPlayer(window, direction);
	this->states[3] = new DancingPlayer(window, direction);
	this->states[4] = new DyingPlayer(window, direction);
	this->states[5] = new RunningShootPlayer(window, direction);
	this->states[6] = new StopPlayer(window, direction);
	this->sprite = this->states[0];
}

int Player::render(Camara &camara)
{
	return camara.render(*this->sprite, this->dest_world);
}

void Player::setIdle()
{
	this->sprite = this->states[0];
}

void Player::setRestIdle()
{
	this->sprite = this->states[1];
}

void Player::setRunning()
{
	this->sprite = this->states[2];
}

void Player::setDancing()
{
	this->sprite = this->states[3];
}

void Player::setDying()
{
	this->sprite = this->states[4];
}

void Player::setRunningShooting()
{
	this->sprite = this->states[5];
}

void Player::setStop()
{
	this->sprite = this->states[6];
}
void Player::setState(const int &state, const int &direction)
{
	(this->*(changeState[state]))();
	this->direction = direction;
}

void Player::setDestWorld(float x, float y, float width, float height)
{
	dest_world.set(x, y, width, height);
}

Player::~Player()
{
	for (auto sprite : states)
	{
		delete sprite.second;
	}
}