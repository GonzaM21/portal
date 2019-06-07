#ifndef OBJECT_H
#define OBJECT_H
#include "../server_model.h"

class Object {
public:
    Object() = default;
    ~Object() = default;
    virtual void aggregate() = 0;
};

#endif