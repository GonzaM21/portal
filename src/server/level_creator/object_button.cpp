#include "object_button.h"

ObjectButton :: ObjectButton(Model *model,float x_pos, float y_pos,int door_id,
    int state_to_open_door) {
    this->model = model;
    this->x_pos = x_pos;
    this->y_pos = y_pos;
    this->door_id = door_id;
    this->state_to_open_door = state_to_open_door;
}

void ObjectButton :: aggregate() {
    this->model->addButton(this->x_pos,this->y_pos,this->door_id,this->state_to_open_door);
}
