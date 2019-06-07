#include "object_acid.h"

ObjectAcid :: ObjectAcid(Model *model,float x_pos, float y_pos, float large) {
    this->model = model;
    this->x_pos = x_pos;
    this->y_pos = y_pos;
    this->large = large;    
}

void ObjectAcid :: aggregate() {
    this->model->addAcid(this->x_pos,this->y_pos,this->large);
}
