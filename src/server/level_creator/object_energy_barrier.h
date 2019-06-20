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
    int orientation;

public:
    ObjectEnergyBarrier(Model *model,float x_pos, float y_pos,float large,
    int orientation);
    ~ObjectEnergyBarrier() = default;
    void aggregate() override;
};

#endif
