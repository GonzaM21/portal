#include <math.h>
#include "Energy_Ball.h"
#include "Macros.h"

Energy_Ball::Energy_Ball(World& world, float x_pos, float y_pos): world(world) {
    Filter_Data data(BALL_BITS);
    data.addMaskBits(CHELL_BITS);
    data.addMaskBits(ROCK_PORTAL_BITS);
    data.addMaskBits(OTHER_BITS);
    energy_ball = world.addCircle(x_pos,y_pos,ENERGY_BALL,false,data);
    energy_ball->SetUserData(this);
    energy_ball->SetGravityScale(0);
    contact = false;
    name = "Energy_Ball";
    live = true;
    radius = ENERGY_BALL;
}

bool Energy_Ball::Move(char direction){
    if(direction == 'R'){
        energy_ball->ApplyForceToCenter(b2Vec2(ENERGY_BALL_FORCE,ZERO),true);
        return true;
    }
    if(direction == 'L'){
        energy_ball->ApplyForceToCenter(b2Vec2(-ENERGY_BALL_FORCE,ZERO),true);
        return true;
    }
    if(direction == 'U'){
        energy_ball->ApplyForceToCenter(b2Vec2(ZERO,ENERGY_BALL_FORCE),true);
        return true;
    }
    if(direction == 'D'){
        energy_ball->ApplyForceToCenter(b2Vec2(ZERO,-ENERGY_BALL_FORCE),true);
        return true;
    }
    return false;
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

std::string Energy_Ball::getEntityName() {
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

void Energy_Ball::changePosition() {
    if(!contact) return;
    energy_ball->SetLinearVelocity(b2Vec2(0,0));
}