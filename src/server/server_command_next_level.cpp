#include <iostream>
#include "server_command_next_level.h"


CommandNextLevel :: CommandNextLevel(Model *model,
   LevelManager *level_manager,std::string &player) {
    this->model = model;
    this->level_manager = level_manager;
    this->player = player;
}

void CommandNextLevel :: execute() {
    this->level_manager->managePlayerVote(this->player,1);
    if (this->level_manager->playersAcceptNextLevel()) {
        this->level_manager->loadNextLevel();
    }
}
