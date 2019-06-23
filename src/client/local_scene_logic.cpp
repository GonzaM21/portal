#include "local_scene_logic.h"

LocalSceneLogic::LocalSceneLogic(SceneManager &scene_manager) :
    scene_manager(scene_manager) {
    this->end_game = false;
    this->next_level = false;
}

void LocalSceneLogic::setEvent(std::string &event) {
    std::unique_lock<std::mutex> lck(m);
    EndLevelScreen *end_level_scene = this->scene_manager.getEndLevelScreen();
    if (event == "q") this->end_game = true;
    else this->next_level = true;
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


//HAY DOS HILOS ACCEDIENDO A ESTA CLASE, PROTEGERRRRRRRRRRRRRRRRRRRRRRRRRRRR