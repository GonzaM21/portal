#include "factory_objetcs.h"

ObjectFactory :: ObjectFactory(Model *model) {
    this->model = model;
}

ObjectRock* ObjectFactory :: createObjectRock(float x_pos, float y_pos, float radius) {
    return new ObjectRock(this->model,x_pos,y_pos,radius);
}

ObjectAcid* ObjectFactory :: createObjectAcid(float x_pos, float y_pos, float large) {
    return new ObjectAcid(this->model,x_pos,y_pos,large);
}

ObjectEnergyBall* ObjectFactory :: createObjectEnergyBall(float x_pos, float y_pos) {
    return new ObjectEnergyBall(this->model,x_pos,y_pos);
}

ObjectMetalBlock* ObjectFactory :: createObjectMetalBlock(float x_pos, float y_pos, float size) {
    return new ObjectMetalBlock(this->model,x_pos,y_pos,size);
}

ObjectGate* ObjectFactory :: createObjectGate(float x_pos,float y_pos) {
    return new ObjectGate(this->model,x_pos,y_pos);
}

ObjectStoneBlock* ObjectFactory :: createObjectStoneBlock(float x_pos, float y_pos, float size) {
    return new ObjectStoneBlock(this->model,x_pos,y_pos,size);
}

ObjectButton* ObjectFactory :: createObjectButton(float x_pos, float y_pos,int door_id,int state_to_open_door) {
    return new ObjectButton(this->model, x_pos, y_pos,door_id,state_to_open_door);
}

ObjectEnergyBarrier* ObjectFactory ::createObjectEnergyBarrier(float x_pos,float y_pos,float large) {
    return new ObjectEnergyBarrier(this->model,x_pos,y_pos,large);
}

ObjectEmitter* ObjectFactory ::createObjectEmitter(float x_pos, float y_pos, 
    float size,std::string& direction, int charged) {
    return new ObjectEmitter(this->model,x_pos,y_pos,size,direction,charged);
}