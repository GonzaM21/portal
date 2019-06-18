#include <iostream>
#include "server_command_next_level.h"


CommandNextLevel :: CommandNextLevel(Model *model,
   LevelManager *level_manager,std::string &player,int vote) {
    this->model = model;
    this->level_manager = level_manager;
    this->player = player;
    this->vote = vote;
}

void CommandNextLevel :: execute() {
    this->level_manager->managePlayerVote(this->player,this->vote);
    if (this->level_manager->playersAcceptNextLevel()) {
        this->level_manager->loadNextLevel();
    }
}
