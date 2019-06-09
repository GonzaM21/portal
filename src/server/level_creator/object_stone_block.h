#ifndef OBJECT_BLOCK_STONE_H
#define OBJECT_BLOCK_STONE_H
#include <string>
#include "object.h"

class ObjectStoneBlock : public Object {
private:
    Model *model;
    float x_pos;
    float y_pos;
    float size;

public:
    ObjectStoneBlock(Model *model,float x_pos, float y_pos,float size);
    ~ObjectStoneBlock() = default;
    void aggregate() override;
};

#endif