#include "Rock.h"

Rock::Rock(World &world, float x_pos, float y_pos,float radius) : world(world){
    Filter_Data data(8);
    data.addMaskBits(1);
    data.addMaskBits(2);
    data.addMaskBits(8);
    data.addMaskBits(16);
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
    return rock->GetPosition();
}

float Rock::getAngle(){
    return rock->GetAngle();
}

void Rock::startContact(b2Vec2 pos) {
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

bool Rock::setTransform(Entity *body) {
    return true;
}

void Rock::changePosition() {}