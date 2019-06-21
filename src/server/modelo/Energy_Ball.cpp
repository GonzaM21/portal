#include <math.h>
#include "Energy_Ball.h"
#include "Macros.h"
#include "Metal_Block.h"
#define ENERGY_BALL 0.5
#define ENERGY_BALL_FORCE 15.0

Energy_Ball::Energy_Ball(World& world, float x_pos, float y_pos): world(world) {
    Filter_Data data(BALL_BITS);
    data.addMaskBits(CHELL_BITS);
    data.addMaskBits(ROCK_PORTAL_BITS);
    data.addMaskBits(OTHER_BITS);
    energy_ball = world.addCircle(x_pos,y_pos,ENERGY_BALL,false,data,false);
    energy_ball->SetUserData(this);
    energy_ball->SetGravityScale(0);
    contact = false;
    change_velocity = false;
    name = "Energy_Ball";
    live = true;
    radius = ENERGY_BALL;
    direction = 0;
}

bool Energy_Ball::Move(char direction){
    if(direction == 'R'){
        velocity = b2Vec2(ENERGY_BALL_FORCE,ZERO);
    } else if(direction == 'L'){
        velocity = b2Vec2(-ENERGY_BALL_FORCE,ZERO);
    }else if(direction == 'U'){
        velocity = b2Vec2(ZERO,ENERGY_BALL_FORCE);
    }else if(direction == 'D'){
        velocity = b2Vec2(ZERO,-ENERGY_BALL_FORCE);
    } else {
        return false;
    }
    energy_ball->SetLinearVelocity(velocity);
    return true;
}

b2Vec2 Energy_Ball::getPosition(){
    if(!live) return b2Vec2(0,0);
    return energy_ball->GetPosition();
}

float Energy_Ball::getAngle() {
    if(!live) return 0;
    return energy_ball->GetAngle();
}

void Energy_Ball::startContact(b2Vec2) {
    contact = true;
}

void Energy_Ball::endContact() {
    contact = false;
}

const std::string& Energy_Ball::getEntityName() {
    return name;
}

void Energy_Ball::die() {
     live = false;
}

bool Energy_Ball::lives(){
    return live;
}

float Energy_Ball::getRadius() {
    return radius;
}

bool Energy_Ball::setTransform(Entity *) {
    return true;
}

void Energy_Ball::changePosition() {}

void Energy_Ball::win(){}

int Energy_Ball::getDirection(){
    if(!live) return 0;
    b2Vec2 actualVelocity = energy_ball->GetLinearVelocity();
    if(abs(actualVelocity.x) > abs(actualVelocity.y)){
        if(actualVelocity.x > 0) direction = 0;
        if(actualVelocity.x < 0) direction = 1;
    } else {
        if(actualVelocity.y > 0) direction = 2;
        if(actualVelocity.y < 0) direction = 3;
    }
    return direction;
}