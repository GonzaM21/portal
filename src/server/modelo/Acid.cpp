#include "Acid.h"
#include "Filter_Data.h"
Acid::Acid(World &world, float x_pos, float y_pos, float large) : world(world) {
    name = "Acid";
    contact = false;
    live = true;
    Filter_Data data(1);
    data.addMaskBits(2);
    acid = world.addPolygon(x_pos, y_pos, large/2, 0.3f,true,data);
    acid->SetUserData(this);
    sizes = b2Vec2(large,0.01);
}

std::string Acid::getEntityName() {
    return name;
}

void Acid::startContact(b2Vec2 pos) {
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

float Acid::getAngle() {
    return acid->GetAngle();
}

b2Vec2 Acid::getSizes(){
    return sizes;
}

bool Acid::setTransform(Entity *body) {
    return true;
}

void Acid::changePosition() {}
