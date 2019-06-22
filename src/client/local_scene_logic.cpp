#include "local_scene_logic.h"

LocalSceneLogic::LocalSceneLogic(SceneManager &scene_manager) :
    scene_manager(scene_manager) {
    this->end_game = false;
    this->next_level = false;
}

void LocalSceneLogic::getClickEvent(int x, int y) {
    EndLevelScreen *end_level_scene = this->scene_manager.getEndLevelScreen();
    if (end_level_scene->clickOnExit(x,y)) this->end_game = true;
    if (end_level_scene->clickOnNext(x,y)) this->next_level = true;
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
