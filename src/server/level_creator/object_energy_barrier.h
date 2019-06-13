#ifndef OBJECT_ENERGY_BARRIER_H
#define OBJECT_ENERGY_BARRIER_H
#include <string>
#include "object.h"

class ObjectEnergyBarrier : public Object {
private:
    Model *model;
    float x_pos;
    float y_pos;
    float large;

public:
    ObjectEnergyBarrier(Model *model,float x_pos, float y_pos,float large);
    ~ObjectEnergyBarrier() = default;
    void aggregate() override;
};

#endif
