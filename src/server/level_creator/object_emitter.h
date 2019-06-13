#ifndef OBJECT_EMITTER_H
#define OBJECT_EMITTER_H
#include <string>
#include "object.h"

class ObjectEmitter : public Object {
private:
    Model *model;
    float x_pos;
    float y_pos;
    float size;
    std::string direction;
    bool charged;

public:
    ObjectEmitter(Model *model,float x_pos, float y_pos, 
        float size,std::string& direction, int charged);
    ~ObjectEmitter() = default;
    void aggregate() override;
};

#endif
