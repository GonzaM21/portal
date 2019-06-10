#ifndef OBJECT_BOTTOMS_H
#define OBJECT_BOTTOMS_H
#include <string>
#include "object.h"

class ObjectBottom : public Object {
private:
    Model *model;
    float x_pos;
    float y_pos;

public:
    ObjectBottom(Model *model,float x_pos, float y_pos);
    ~ObjectBottom() = default;
    void aggregate() override;
};

#endif
