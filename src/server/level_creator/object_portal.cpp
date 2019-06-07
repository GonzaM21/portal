#include "object_portal.h"

ObjectPortal :: ObjectPortal(Model *model) {
    this->model = model;
}

void ObjectPortal :: aggregate() {
    std::cout << "Agrega el objecto portal\n";
}