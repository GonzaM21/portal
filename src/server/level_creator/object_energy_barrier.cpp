#include "object_energy_barrier.h"

ObjectEnergyBarrier :: ObjectEnergyBarrier(Model *model,float x_pos, float y_pos,float large,
    int orientation) {
    this->model = model;
    this->x_pos = x_pos;
    this->y_pos = y_pos;
    this->large = large;
    this->orientation = orientation;
}

void ObjectEnergyBarrier :: aggregate() {
    this->model->addEnergyBarrier(this->x_pos,this->y_pos,this->large,this->orientation);
}
