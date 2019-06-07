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

