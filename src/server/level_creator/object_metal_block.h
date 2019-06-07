#ifndef OBJECT_BLOCK_METAL_H
#define OBJECT_BLOCK_METAL_H
#include <string>
#include "object.h"

class ObjectMetalBlock : public Object {
private:
    Model *model;
    float x_pos;
    float y_pos;
    float size;

public:
    ObjectMetalBlock(Model *model,float x_pos, float y_pos,float size);
    ~ObjectMetalBlock() = default;
    void aggregate() override;
};

#endif