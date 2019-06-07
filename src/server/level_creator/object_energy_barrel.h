#ifndef OBJECT_ENERGY_BARREL_H
#define OBJECT_ENERGY_BARREL_H
#include <string>
#include "object.h"

class ObjectEnergyBarrel : public Object {
private:
    Model *model;

public:
    ObjectEnergyBarrel(Model *model);
    ~ObjectEnergyBarrel() = default;
    void aggregate() override;
};

#endif