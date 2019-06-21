#include "scene_manager.h"

void SceneManager::renderAll() {
    this->model_facade.renderAll();
}

void SceneManager::decodeObjectMessage(std::vector<std::string> &arguments) {
    this->model_facade.decodeMessages(arguments);
}

ModelFacade* SceneManager::getModelFacade() {
    return &this->model_facade;
}