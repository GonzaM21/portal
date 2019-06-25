#include "scene_manager.h"
#include "../vista/next_level_screen/screen_constants.h"
#include "../vista/end_game_scene/end_game_constants.h"

SceneManager::SceneManager() :
    window(800,800) ,  
    model_controller(window),
    end_level_scene(window),
    end_game_scene(window),
    ffmpeg() {
    this->window.setBackground(BACKGROUND_FILENAME);
    this->actual_screen = 0;
    this->level_change = false;
    this->recording = false;
    this->full_screen = false;
}

void SceneManager::renderAll() {
    window.fill();
    if (this->actual_screen == 0) {
        if (this->level_change) {
            this->level_change = false;
        }
        this->model_controller.renderAll();
    }
    if (this->actual_screen == 1) {
        this->level_change = true;
        this->end_level_scene.renderScene();
    }
    if (this->actual_screen == 2) this->end_game_scene.renderScene();
    window.render();
}

void SceneManager::decodeObjectMessage(std::vector<std::string> &arguments) {
    this->model_controller.decodeMessages(arguments);
}

ModelController* SceneManager::getModelController() {
    return &this->model_controller;
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

void SceneManager::putEndGameScene() {
    this->setActualScreen(EXIT_GAME_SCREEN);
    this->window.setBackground(END_GAME_BACKGROUND_PATH);
}

void SceneManager::putGameScene() {
    this->setActualScreen(GAME_SCREEN);
    this->window.setBackground(BACKGROUND_FILENAME);
}


void SceneManager::resetLevelStage() {
    model_controller.resetModel();
}

void SceneManager::setFullScreen() {
    if (this->full_screen) {
        if (this->recording) {
            this->record();
        }
        this->full_screen=false;
    } else {
        this->full_screen=true;
    }
    window.fullscreen();
}

void SceneManager::record() {
    if (!this->full_screen) this->setFullScreen();
    if (this->recording) {
        this->recording = false;
        this->ffmpeg.stopRecording();
    } else {
        this->recording = true;
        this->ffmpeg.recordScreen();
    }
}  

void SceneManager::stopRocording() {
    if (this->recording) this->record();
}