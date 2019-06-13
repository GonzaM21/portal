#include "object_emitter.h"

ObjectEmitter :: ObjectEmitter(Model *model,float x_pos, 
    float y_pos, float size,std::string& direction, int charged) {
    this->model = model;
    this->x_pos = x_pos;
    this->y_pos = y_pos;
    this->size = size;
    this->direction = direction;
    this->charged = (bool)charged;
}

void ObjectEmitter :: aggregate() {
    this->model->addEmitter(this->x_pos,this->y_pos,this->size,
    this->direction,this->charged);
}
