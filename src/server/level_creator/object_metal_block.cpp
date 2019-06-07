#include "object_metal_block.h"

ObjectMetalBlock :: ObjectMetalBlock(Model *model,float x_pos, float y_pos,float size) {
    this->model = model;
    this->x_pos = x_pos;
    this->y_pos = y_pos;
    this->size = size;
}

void ObjectMetalBlock :: aggregate() {
    this->model->addMetalBlock(this->x_pos,this->y_pos,this->size);
}