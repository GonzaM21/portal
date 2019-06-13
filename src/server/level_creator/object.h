#ifndef OBJECT_H
#define OBJECT_H
#include "../server_model.h"

class Object {
public:
    Object() = default;
    virtual ~Object() {}
    virtual void aggregate() = 0;
};

#endif