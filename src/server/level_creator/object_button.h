#ifndef OBJECT_BUTTON_H
#define OBJECT_BUTTON_H
#include <string>
#include "object.h"

class ObjectButton : public Object {
private:
    Model *model;
    float x_pos;
    float y_pos;

public:
    ObjectButton(Model *model,float x_pos, float y_pos);
    ~ObjectButton() = default;
    void aggregate() override;
};

#endif
