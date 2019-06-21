#include "Rock.h"
#include "Macros.h"

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
    live = false;
}

bool Rock::lives() {
    return live;
}

float Rock::getRadius(){
    return this->radius;
}

bool Rock::setTransform(Entity *) {
    return true;
}

void Rock::setGravity(int gravity) {
    rock->SetGravityScale(gravity);
}

void Rock::changePosition() {}

void Rock::win(){}

void Rock::changePositionChell(b2Vec2 pos) {
    rock->SetTransform(pos,ZERO);
}
