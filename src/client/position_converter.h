#ifndef POSITION_CONVERTER_H
#define POSITION_CONVERTER_H
#include "../vista/ModelController.h"
#include <vector>

class PositionConverter {
private:
    ModelController *model_controller;
public:
    PositionConverter(ModelController *model_controller);
    ~PositionConverter() = default;
    //std::vector<int> convertToVirtual(int x, int y);

    //Toma como parametro un x e y en el sistema de referencia
    //de la camara y lo transforma en un x e y del sistema
    //de referencia de box2d.
    std::vector<int> convertToWorld(int x, int y);
};

#endif