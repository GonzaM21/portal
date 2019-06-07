#include "object_door.h"

ObjectDoor :: ObjectDoor(Model *model) {
    this->model = model;
}

void ObjectDoor :: aggregate() {
    std::cout << "Agrega el objecto door\n";
}