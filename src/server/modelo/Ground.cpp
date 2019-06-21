#include "Ground.h"
#include "Macros.h"
Ground::Ground(World &world,float x_pos, float y_pos,  float width, float high){
    Filter_Data data(OTHER_BITS);
    data.addMaskBits(CHELL_BITS);
    data.addMaskBits(BARRIER_BITS);
    data.addMaskBits(ROCK_PORTAL_BITS);
    data.addMaskBits(BALL_BITS);
    ground = world.addPolygon(x_pos - DELTA_POSITION,y_pos - DELTA_POSITION,width/2.f,high/2.f,true,data);
    ground->SetUserData(this);
    sizes = b2Vec2(width,high);
    name = "Ground";
}

b2Vec2 Ground::getSizes() {
    return sizes;
}

const std::string& Ground::getEntityName(){
    return name;
}

void Ground::startContact(b2Vec2){}

void Ground::endContact(){}

void Ground::die(){}

bool Ground::lives(){
    return true;
}

bool Ground::setTransform(Entity *){
    return true;
}

void Ground::changePosition(){}

b2Vec2 Ground::getPosition(){
    return ground->GetPosition();
}

void Ground::win() {}
