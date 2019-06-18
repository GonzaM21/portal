#include "object_cake.h"

ObjectCake :: ObjectCake(Model *model,float x_pos, float y_pos) {
    this->model = model;
    this->x_pos = x_pos;
    this->y_pos = y_pos;
}

void ObjectCake :: aggregate() {
    this->model->addCake(this->x_pos,this->y_pos);
}
