#include "object_rock.h"

ObjectRock :: ObjectRock(Model *model,float x_pos, float y_pos, float radius) {
    this->model = model;
    this->x_pos = x_pos;
    this->y_pos = y_pos;
    this->radius = radius;
}

void ObjectRock :: aggregate() {
    model->addRock(this->x_pos,this->y_pos,this->radius);
}
