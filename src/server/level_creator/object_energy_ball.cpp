#include "object_energy_ball.h"

ObjectEnergyBall :: ObjectEnergyBall(Model *model,float x_pos, float y_pos) {
    this->model = model;
    this->x_pos = x_pos;
    this->y_pos = y_pos;
}

void ObjectEnergyBall :: aggregate() {
    this->model->addEnergyBall(this->x_pos,this->y_pos);
}