#ifndef OBJECT_ENERGY_BALL_H
#define OBJECT_ENERGY_BALL_H
#include <string>
#include "object.h"

class ObjectEnergyBall : public Object {
private:
    Model *model;
    float x_pos; 
    float y_pos;

public:
    ObjectEnergyBall(Model *model,float x_pos, float y_pos);
    ~ObjectEnergyBall() = default;
    void aggregate() override;
};

#endif