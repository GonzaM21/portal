#include "object_lunch_block.h"

ObjectLunchBlock :: ObjectLunchBlock(Model *model) {
    this->model = model;
}

void ObjectLunchBlock :: aggregate() {
    std::cout << "Agrega el objecto lunck block\n";
}