#ifndef OBJECT_DOOR_H
#define OBJECT_DOOR_H
#include <string>
#include "object.h"

class ObjectDoor : public Object {
private:
    Model *model;

public:
    ObjectDoor(Model *model);
    ~ObjectDoor() = default;
    void aggregate() override;
};

#endif