#include "Rock.h"
#include "Macros.h"
#include "Portal.h"
#define BALL_X_DELTA 0.8
#define BALL_Y_DELTA 0.8
#define BALL_VELOC 2

Rock::Rock(World &world, float x_pos, float y_pos,float radius) : world(world){
    Filter_Data data(ROCK_PORTAL_BITS);
    data.addMaskBits(OTHER_BITS);
    data.addMaskBits(CHELL_BITS);
    data.addMaskBits(BARRIER_BITS);
    data.addMaskBits(ROCK_PORTAL_BITS);
    data.addMaskBits(BALL_BITS);
    rock = world.addCircle(x_pos,y_pos,radius,false,data,true);
    rock->SetUserData(this);
    this->radius = radius;
    name = "Rock";
    contact = false;
    live = true;
    teleport = false;
    velocity = b2Vec2(0,0);
    teleport_pos = b2Vec2(0,0);
}

const std::string& Rock::getEntityName() {
    return name;
}

b2Vec2 Rock::getPosition() {
    return rock->GetPosition();
}

void Rock::startContact(b2Vec2) {
    contact = true;
}

void Rock::endContact() {
    contact = false;
}

void Rock::die() {
    live = true;
}

bool Rock::lives() {
    return live;
}

float Rock::getRadius(){
    return this->radius;
}

bool Rock::setTransform(Entity * body) {
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

        velocity = b2Vec2(BALL_VELOC * normal.x,BALL_VELOC * normal.y);
    }
}

void Rock::setGravity(int gravity) {
    rock->SetGravityScale(gravity);
}

void Rock::changePosition() {
    if(!teleport) return;
    rock->SetTransform(teleport_pos,rock->GetAngle());
    rock->SetLinearVelocity(velocity);
    teleport = false;
}

void Rock::win(){}

void Rock::changePositionChell(b2Vec2 pos) {
    rock->SetTransform(pos,ZERO);
}
