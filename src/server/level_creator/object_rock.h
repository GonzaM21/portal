#ifndef OBJECT_ROCK_H
#define OBJECT_ROCK_H
#include <string>
#include "object.h"

class ObjectRock : public Object {
private:
    Model *model;
    float x_pos;
    float y_pos;
    float radius;

public:
    ObjectRock(Model *model,float x_pos, float y_pos, float radius);
    ~ObjectRock() = default;
    void aggregate() override;
};

#endif
