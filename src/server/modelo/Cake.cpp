#include "Cake.h"
#include "Macros.h"
#define CAKE_SIZE 0.5
#define REAL_HIGH 0.2
#define REAL_WIDTH 0.4

Cake::Cake(World &world, float x_pos, float y_pos) {
    Filter_Data data(OTHER_BITS);
    data.addMaskBits(CHELL_BITS);
    data.addMaskBits(BARRIER_BITS);
    data.addMaskBits(ROCK_PORTAL_BITS);
    data.addMaskBits(BALL_BITS);
    cake = world.addPolygon(x_pos,y_pos,REAL_WIDTH,REAL_HIGH,true,data);
    name = "Cake";
    cake->SetUserData(this);
    sizes = b2Vec2(CAKE_SIZE,CAKE_SIZE);
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

void Cake::win() {}
