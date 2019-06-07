#ifndef OBJECT_LUNCH_BLOCK_H
#define OBJECT_LUNCH_BLOCK_H
#include <string>
#include "object.h"

class ObjectLunchBlock : public Object {
private:
    Model *model;

public:
    ObjectLunchBlock(Model *model);
    ~ObjectLunchBlock() = default;
    void aggregate() override;
};

#endif