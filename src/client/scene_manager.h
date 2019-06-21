#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H
#include "../vista/ModelFacade.h"
#include <string>
#include <vector>


class SceneManager {
private: 
    ModelFacade model_facade;

public:
    SceneManager() = default;
    ~SceneManager() = default;
    void renderAll();
    void decodeObjectMessage(std::vector<std::string> &arguments);
    ModelFacade *getModelFacade();
};

#endif