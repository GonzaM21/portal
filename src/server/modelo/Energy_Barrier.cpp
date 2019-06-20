#include "Energy_Barrier.h"
#define PI 3.14159265359

Energy_Barrier::Energy_Barrier(World &world, float x_pos, float y_pos, float large,int orientation) : world(world), orientation(orientation){
    Filter_Data data(BARRIER_BITS);
    data.addMaskBits(OTHER_BITS);
    data.addMaskBits(ROCK_PORTAL_BITS);
    barrier = world.addPolygon(x_pos,y_pos,ENERGY_BARRIER_WIDTH,large/2.f,true,data);
    if (orientation == 2){
        barrier->SetTransform(barrier->GetPosition(),90 * PI/180 );
    }
    barrier->SetUserData(this);
    sizes = b2Vec2(ENERGY_BARRIER_WIDTH,large);
    name = "Energy_Barrier";
}

const std::string& Energy_Barrier::getEntityName(){
    return name;
}

void Energy_Barrier::startContact(b2Vec2){}

void Energy_Barrier::endContact(){}

void Energy_Barrier::die(){}

bool Energy_Barrier::lives(){
    return true;
}

bool Energy_Barrier::setTransform(Entity *){
    return true;
}

void Energy_Barrier::changePosition(){}

b2Vec2 Energy_Barrier::getSizes(){
    return sizes;
}

b2Vec2 Energy_Barrier::getPosition() {
    return barrier->GetPosition();
}

void Energy_Barrier::startBouncing() {}

void Energy_Barrier::win() {}