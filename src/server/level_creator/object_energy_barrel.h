#ifndef OBJECT_ENERGY_BARREL_H
#define OBJECT_ENERGY_BARREL_H
#include <string>
#include "object.h"

class ObjectEnergyBarrel : public Object {
private:
    Model *model;
    float large;

public:
    ObjectEnergyBarrel(Model *model,float large);
    ~ObjectEnergyBarrel() = default;
    void aggregate() override;
};

#endif