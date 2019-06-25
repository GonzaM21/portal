#include "Player.h"
#include "../Window.h"
#include "Idle_player.h"
#include "RestingIdle_player.h"
#include "Stop_player.h"
#include "Dying_player.h"
#include "Running_player.h"
#include "Dancing_player.h"
#include "RunningShoot_player.h"
#include "JumpFall_player.h"
#include "JumpRise_player.h"
#include "../Constants.h"
#include "../Camara.h"
#include "../MusicBase.h"
#include <string>
#include <iostream>
#include <functional>
#include <typeinfo>

Player::Player(const Window &window, const int &direction, const int &id) : dest_world(0, 0, 0, 0), direction(direction), id(id){
	this->changeState[0] = &Player::setIdle;
	this->changeState[1] = &Player::setRestIdle;
	this->changeState[2] = &Player::setRunning;
	this->changeState[3] = &Player::setDancing;
	this->changeState[4] = &Player::setDying;
	this->changeState[5] = &Player::setRunningShooting;
	this->changeState[6] = &Player::setStop;
	this->changeState[7] = &Player::setRising;
	this->changeState[8] = &Player::setFalling;
	this->states[0] = new IdlePlayer(window, direction, id);
	this->states[1] = new RestingIdlePlayer(window, direction, id);
	this->states[2] = new RunningPlayer(window, direction, id);
	this->states[3] = new DancingPlayer(window, direction, id);
	this->states[4] = new DyingPlayer(window, direction, id);
	this->states[5] = new RunningShootPlayer(window, direction, id);
	this->states[6] = new StopPlayer(window, direction, id);
	this->states[7] = new RisingPlayer(window, direction, id);
	this->states[8] = new FallingPlayer(window, direction, id);
	this->sprite = this->states[0];
}

int Player::render(Camara &camara) {
	return camara.render(*this->sprite, this->dest_world);
}

void Player::setIdle() {
	if (strcmp(typeid(*this->sprite).name(), typeid(*this->states[0]).name()) != 0) {
		this->sprite = this->states[0];
	}
}

void Player::setRestIdle() {
	if (strcmp(typeid(*this->sprite).name(), typeid(*this->states[1]).name()) != 0) {
		this->sprite = this->states[1];
	}
}

void Player::setRunning() {
	if (strcmp(typeid(*this->sprite).name(), typeid(*this->states[2]).name()) != 0) {
		this->sprite = this->states[2];
		//MusicBase::getInstance()->playMusic(CHELL_STEP_FX_ID,15);
	}
}

void Player::setDancing() {
	if (strcmp(typeid(*this->sprite).name(), typeid(*this->states[3]).name()) != 0) {
		this->sprite = this->states[3];
        MusicBase::getInstance()->playMusic(CHELL_WIN_ID,15);
	}
}

void Player::setDying() {
	if (strcmp(typeid(*this->sprite).name(), typeid(*this->states[4]).name()) != 0) {
		this->sprite = this->states[4];
		MusicBase::getInstance()->playMusic(CHELL_SCREAM_ID,15);
	}
}


void Player::setRunningShooting() {
	if (strcmp(typeid(*this->sprite).name(), typeid(*this->states[5]).name()) != 0) {
		this->sprite = this->states[5];
	}
	
}

void Player::setStop() {
	if (strcmp(typeid(*this->sprite).name(), typeid(*this->states[6]).name()) != 0) {
		this->sprite = this->states[6];
	}
}

void Player::setRising() {
	if (strcmp(typeid(*this->sprite).name(), typeid(*this->states[7]).name()) != 0) {
		this->sprite = this->states[7];
		MusicBase::getInstance()->playMusic(CHELL_JUMP_FX_ID,10);
	}
}

void Player::setFalling() {
	if (strcmp(typeid(*this->sprite).name(), typeid(*this->states[8]).name()) != 0) {
		this->sprite = this->states[8];
	}
}
void Player::setState(const int &state, const int &direction)
{
	(this->*(changeState[state]))();
	this->sprite->setDirection(direction);
	this->direction = direction;
}

void Player::setDestWorld(float x, float y, float width, float height)
{
	dest_world.set(x, y, width, height);
}

Player::~Player() {
	for (auto it = this->states.cbegin(); it != this->states.cend();) {
		delete it->second;
		it = this->states.erase(it);
	}
}