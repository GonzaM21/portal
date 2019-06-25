#include "position_converter.h"

PositionConverter::PositionConverter(ModelController *model_controller) {
    this->model_controller = model_controller;
}

//std::vector<int> PositionConverter::convertToVirtual(int x, int y) {
//
//}

std::vector<int> PositionConverter::convertToWorld(int x, int y) {
    Rect virtualPos(x,y,0,0);
    Rect worldPos(0,0,0,0);
    this->model_controller->convertToWorld(worldPos,virtualPos);
    std::vector<int> new_coords;
    new_coords.push_back(worldPos.getX());
    new_coords.push_back(worldPos.getY());
    return std::move(new_coords);
}