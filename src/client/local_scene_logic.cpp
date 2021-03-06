#include "local_scene_logic.h"

LocalSceneLogic::LocalSceneLogic(SceneManager &scene_manager) :
    scene_manager(scene_manager) {
    this->end_game = false;
    this->next_level = false;
}

void LocalSceneLogic::setEvent(std::string &event) {
    std::unique_lock<std::mutex> lck(m);
    if (event == "q") {
        this->end_game = true;
        this->scene_manager.putEndGameScene();
    } else {
        this->next_level = true;
    }
}

bool LocalSceneLogic::getEndGame() {
    return this->end_game;
}

bool LocalSceneLogic::getNextLevel() {
    return this->next_level;
}

void LocalSceneLogic::resetLocalSceneLogic() {
    this->end_game = false;
    this->next_level = false;
}

void LocalSceneLogic::setFullScreen() {
    this->scene_manager.setFullScreen();
}

void LocalSceneLogic::record() {
    this->scene_manager.record();
}