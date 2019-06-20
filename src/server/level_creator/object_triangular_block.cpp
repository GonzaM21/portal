#include "object_triangular_block.h"

ObjectTriangularBlock :: ObjectTriangularBlock(Model *model,float x_pos, float y_pos,
    float size, int type) {
    this->model = model;
    this->x_pos = x_pos;
    this->y_pos = y_pos;
    this->size = size;
    this->type = type;
}

void ObjectTriangularBlock :: aggregate() {
    this->model->addTriangularBlock(this->x_pos,this->y_pos,this->size,this->type);
}