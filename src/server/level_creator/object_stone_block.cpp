#include "object_stone_block.h"

ObjectStoneBlock :: ObjectStoneBlock(Model *model,float x_pos, float y_pos,float size) {
    this->model = model;
    this->x_pos = x_pos;
    this->y_pos = y_pos;
    this->size = size;
}

void ObjectStoneBlock :: aggregate() {
    this->model->addStoneBlock(this->x_pos,this->y_pos,this->size);
}
