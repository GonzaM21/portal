#ifndef OBJECT_PORTAL_H
#define OBJECT_PORTAL_H
#include <string>
#include "object.h"

class ObjectPortal : public Object {
private:
    Model *model;

public:
    ObjectPortal(Model *model);
    ~ObjectPortal() = default;
    void aggregate() override;
};

#endif