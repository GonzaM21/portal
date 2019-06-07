#ifndef OBJECT_ACID_H
#define OBJECT_ACID_H
#include <string>
#include "object.h"

class ObjectAcid : public Object {
private:
    Model *model;
    float x_pos;
    float y_pos; 
    float large;

public:
    ObjectAcid(Model *model,float x_pos, float y_pos, float large);
    ~ObjectAcid() = default;
    void aggregate() override;
};

#endif
