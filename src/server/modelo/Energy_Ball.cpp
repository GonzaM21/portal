#include <math.h>
#include "Energy_Ball.h"
#include "Macros.h"
#include "Metal_Block.h"
#include "Portal.h"
#define ENERGY_BALL 0.5
#define ENERGY_BALL_FORCE 3.0
#define LIFE_STEPS 200
#define BALL_X_DELTA 0.8
#define BALL_Y_DELTA 0.8

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
    life_step = 0;
    teleport = 0;
    teleport_pos = b2Vec2(0,0);
    velocity = b2Vec2(0,0);
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

bool Energy_Ball::setTransform(Entity * body) {
    if (body->getEntityName() == "Portal") {
        if(dynamic_cast<Portal *>(body)->isABall()) return false;
        if(!dynamic_cast<Portal *>(body)->havePartner()) return false;
        if(dynamic_cast<Portal *>(body)->getPartnerPortal() == nullptr) return false;
        if(!dynamic_cast<Portal *>(body)->getPartnerPortal()->lives()) return false;


        teleport_pos = dynamic_cast<Portal *>(body)->getPartnerPortal()->getPosition();
        b2Vec2 normal = dynamic_cast<Portal *>(body)->getPartnerPortal()->getNormal();

        teleport = true;
        if(normal.x > ZERO){
            teleport_pos = teleport_pos + b2Vec2(BALL_X_DELTA,ZERO);
        } else if(normal.x < ZERO){
            teleport_pos = teleport_pos - b2Vec2(BALL_X_DELTA,ZERO);
        }
        if(normal.y > ZERO){
            teleport_pos = teleport_pos + b2Vec2(ZERO,BALL_Y_DELTA);
        } else if (normal.y < ZERO){
            teleport_pos = teleport_pos - b2Vec2(ZERO,BALL_Y_DELTA);
        }

        velocity = b2Vec2(ENERGY_BALL_FORCE * normal.x,ENERGY_BALL_FORCE * normal.y);
    }
    return true;
}

void Energy_Ball::changePosition() {
    if(life_step == LIFE_STEPS) live = false;
    ++life_step;
    if(!teleport) return;
    energy_ball->SetTransform(teleport_pos,energy_ball->GetAngle());
    energy_ball->SetLinearVelocity(velocity);
    teleport = false;
}

void Energy_Ball::win(){}

int Energy_Ball::getDirection(){
    if(!live) return 0;
    b2Vec2 actualVelocity = energy_ball->GetLinearVelocity();
    if(abs(actualVelocity.x) > abs(actualVelocity.y)){
        if(actualVelocity.x > 0) direction = 2;
        if(actualVelocity.x < 0) direction = 4;
    } else {
        if(actualVelocity.y > 0) direction = 1;
        if(actualVelocity.y < 0) direction = 3;
    }
    return direction;
}