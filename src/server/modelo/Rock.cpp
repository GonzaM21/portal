#include "Rock.h"

Rock::Rock(World &world, float x_pos, float y_pos,float radius) : world(world){
    Filter_Data data(ROCK_PORTAL_BITS);
    data.addMaskBits(OTHER_BITS);
    data.addMaskBits(CHELL_BITS);
    data.addMaskBits(BARRIER_BITS);
    data.addMaskBits(ROCK_PORTAL_BITS);
    data.addMaskBits(BALL_BITS);
    rock = world.addCircle(x_pos,y_pos,radius,false,data);
    rock->SetUserData(this);
    radius = radius;
    name = "Rock";
    contact = false;
    live = true;
}

std::string Rock::getEntityName() {
    return name;
}

b2Vec2 Rock::getPosition() {
    //std::cout<<"Velocity: "<<rock->GetLinearVelocity().x<<" "<<rock->GetLinearVelocity().y<<std::endl;
    return rock->GetPosition();
}

float Rock::getAngle(){
    return rock->GetAngle();
}

void Rock::startContact(b2Vec2) {
    contact = true;
}

void Rock::endContact() {
    contact = false;
}

void Rock::die() {
    live = true; //No tiene que morir
}

bool Rock::lives() {
    return live;
}

float Rock::getRadius(){
    return radius;
}

bool Rock::setTransform(Entity *) {
    return true;
}

void Rock::changePosition() {}