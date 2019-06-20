#ifndef OBJECT_TRIAGULAR_BLOCK_H
#define OBJECT_TRIAGULAR_BLOCK_H
#include <string>
#include "object.h"

class ObjectTriangularBlock : public Object {
private:
    Model *model;
    float x_pos;
    float y_pos;
    float size;
    int type;

public:
    ObjectTriangularBlock(Model *model,float x_pos, float y_pos,float size,int type);
    ~ObjectTriangularBlock() = default;
    void aggregate() override;
};

#endif
