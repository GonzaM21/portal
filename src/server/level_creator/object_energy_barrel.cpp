#include "object_energy_barrel.h"

ObjectEnergyBarrel :: ObjectEnergyBarrel(Model *model) {
    this->model = model;
}

void ObjectEnergyBarrel :: aggregate() {
    std::cout << "Agrega el objecto acid\n";
}