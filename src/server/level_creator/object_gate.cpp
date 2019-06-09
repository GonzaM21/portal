#include "object_gate.h"

ObjectGate :: ObjectGate(Model *model,float x_pos, float y_pos) {
    this->model = model;
    this->x_pos = x_pos;
    this->y_pos = y_pos;
}

void ObjectGate :: aggregate() {
    this->model->addGate(this->x_pos,this->y_pos);
}
