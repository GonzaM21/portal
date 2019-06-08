#include "Bottom.h"
#include "Filter_Data.h"

Bottom::Bottom(World &world, float x_pos, float y_pos) : world(world) {
    Filter_Data data(0);
    bottom = world.addPolygon(x_pos,y_pos,BOTTOM_LARGE/2,BOTTOM_HIGH/2,true,data);
    bottom->SetUserData(this);
    sizes = b2Vec2(BOTTOM_LARGE,BOTTOM_HIGH);
    contact = false;
    live = true;
    status = false;
    name = "Bottom";
}

std::string Bottom::getEntityName() {
    return name;
}

bool Bottom::lives() {
    return live;
}

void Bottom::die() {
    live = false;
}

void Bottom::startContact(b2Vec2 pos) {
    contact = true;
    status = true;
}

void Bottom::endContact() {
    contact = false;
    status = false;
}

bool Bottom::setTransform(Entity *body) {
    return true;
}

void Bottom::changePosition() {}

b2Vec2 Bottom::getPosition() {
    if (!live) return b2Vec2(0,0);
    return bottom->GetPosition();
}

float Bottom::getAngle() {
    if(!live) return 0;
    return bottom->GetAngle();
}

b2Vec2 Bottom::getSizes() {
    return sizes;
}

bool Bottom::getStatus(){
    return status;
}