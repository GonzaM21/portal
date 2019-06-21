#include "Acid.h"
#include "Filter_Data.h"
#include "Macros.h"

Acid::Acid(World &world, float x_pos, float y_pos, float large) : world(world) {
    name = "Acid";
    contact = false;
    live = true;
    Filter_Data data(OTHER_BITS);
    data.addMaskBits(CHELL_BITS);
    acid = world.addPolygon(x_pos, y_pos, large/2, 0.01f,true,data);
    acid->SetUserData(this);
    sizes = b2Vec2(large,0.01);
}

const std::string& Acid::getEntityName() {
    return name;
}

void Acid::startContact(b2Vec2) {
    contact = true;
}

void Acid::endContact() {
    contact = false;
}

void Acid::die() {
    live = true; //No tiene que morir
}

bool Acid::lives() {
    return live;
}

b2Vec2 Acid::getPosition() {
    return acid->GetPosition();
}

b2Vec2 Acid::getSizes(){
    return sizes;
}

bool Acid::setTransform(Entity *) {
    return true;
}

void Acid::changePosition() {}

void Acid::win() {}