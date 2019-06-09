#include "Energy_Barrier.h"

Energy_Barrier::Energy_Barrier(World &world, float x_pos, float y_pos, float large) : world(world){
    Filter_Data data(4);
    data.addMaskBits(1);
    data.addMaskBits(8);
    barrier = world.addPolygon(x_pos,y_pos,ENERGY_BARRIER_WIDTH,large/2.f,true,data);
    barrier->SetUserData(this);
    sizes = b2Vec2(ENERGY_BARRIER_WIDTH,large);
    name = "Energy_Barrier";
}

std::string Energy_Barrier::getEntityName(){
    return name;
}

void Energy_Barrier::startContact(b2Vec2 pos){}

void Energy_Barrier::endContact(){}

void Energy_Barrier::die(){}

bool Energy_Barrier::lives(){
    return true;
}

bool Energy_Barrier::setTransform(Entity * body){
    return true;
}

void Energy_Barrier::changePosition(){}

b2Vec2 Energy_Barrier::getSizes(){
    return sizes;
}

b2Vec2 Energy_Barrier::getPosition() {
    return barrier->GetPosition();
}