#include "object_energy_barrel.h"

ObjectEnergyBarrel :: ObjectEnergyBarrel(Model *model,float large) {
    this->model = model;
    this->large =large;
}

void ObjectEnergyBarrel :: aggregate() {
    std::cout << "Agrega el objecto acid\n";
}