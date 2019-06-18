#ifndef OBJECT_CAKE_H
#define OBJECT_CAKE_H
#include <string>
#include "object.h"

class ObjectCake : public Object {
private:
    Model *model;
    float x_pos;
    float y_pos;

public:
    ObjectCake(Model *model,float x_pos,float y_pos);
    ~ObjectCake() = default;
    void aggregate() override;
};

#endif