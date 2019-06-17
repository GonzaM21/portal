#include "Cake.h"

Cake::Cake(World &world, float x_pos, float y_pos) {
    Filter_Data data(OTHER_BITS);
    data.addMaskBits(CHELL_BITS);
    data.addMaskBits(BARRIER_BITS);
    data.addMaskBits(ROCK_PORTAL_BITS);
    data.addMaskBits(BALL_BITS);
    cake = world.addBox(x_pos,y_pos,0.5,true,data);
    name = "Cake";
    sizes = b2Vec2(0.5,0.5);
}

const std::string& Cake::getEntityName() {
    return name;
}

void Cake::startContact(b2Vec2) {}

void Cake::endContact() {}

void Cake::die() {}

bool Cake::lives() {
    return true;
}

b2Vec2 Cake::getPosition() {
    return cake->GetPosition();
}

b2Vec2 Cake::getSizes(){
    return sizes;
}

bool Cake::setTransform(Entity *) {
    return true;
}

void Cake::changePosition() {}

void Cake::startBouncing() {}

void Cake::win() {}
