#include "object_bottoms.h"

ObjectBottom :: ObjectBottom(Model *model,float x_pos, float y_pos) {
    this->model = model;
    this->x_pos = x_pos;
    this->y_pos = y_pos;
}

void ObjectBottom :: aggregate() {
    this->model->addBottom(this->x_pos,this->y_pos);
}
