#include "position_converter.h"

PositionConverter::PositionConverter(ModelFacade *model_facade) {
    this->model_facade = model_facade;
}

//std::vector<int> PositionConverter::convertToVirtual(int x, int y) {
//
//}

std::vector<int> PositionConverter::convertToWorld(int x, int y) {
    Rect virtualPos(x,y,0,0);
    Rect worldPos(0,0,0,0);
    this->model_facade->convertToWorld(worldPos,virtualPos);
    std::vector<int> new_coords;
    new_coords.push_back(worldPos.getX());
    new_coords.push_back(worldPos.getY());
    return std::move(new_coords);
}