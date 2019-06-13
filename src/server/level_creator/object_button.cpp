#include "object_button.h"

ObjectButton :: ObjectButton(Model *model,float x_pos, float y_pos) {
    this->model = model;
    this->x_pos = x_pos;
    this->y_pos = y_pos;
}

void ObjectButton :: aggregate() {
    this->model->addButton(this->x_pos,this->y_pos);
}
