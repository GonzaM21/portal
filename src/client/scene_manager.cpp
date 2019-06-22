#include "scene_manager.h"
#include "../vista/next_level_screen/screen_constants.h"
SceneManager::SceneManager() :
    window(800,800) ,  
    model_facade(window),
    end_level_screen(window){
    this->window.setBackground(BACKGROUND_FILENAME);
    this->actual_screen = 0;
}

void SceneManager::renderAll() {
    window.fill();
    if (this->actual_screen == 0) this->model_facade.renderAll();
    if (this->actual_screen == 1) this->end_level_screen.renderScene();
    window.render();
}

void SceneManager::decodeObjectMessage(std::vector<std::string> &arguments) {
    this->model_facade.decodeMessages(arguments);
}

ModelFacade* SceneManager::getModelFacade() {
    return &this->model_facade;
}

int SceneManager::getActualScreen() {
    return this->actual_screen;
}

void SceneManager::setActualScreen(int screen_num) {
    this->actual_screen = screen_num;
}

void SceneManager::putNextLevelScene() {
    this->setActualScreen(END_LEVEL_SCREEN);
    this->window.setBackground(BACKGROUND_PATH);
}

void SceneManager::putGameScene() {
    this->setActualScreen(GAME_SCREEN);
    this->window.setBackground(BACKGROUND_FILENAME);
}

EndLevelScreen* SceneManager::getEndLevelScreen() {
    return &this->end_level_screen;
}