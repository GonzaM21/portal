#include "server_level_manager.h"
#define LEVEL_1 "json_prueba12"
#define LEVEL_2 "json_file2"

void LevelManager::setVotes() {
    for (auto player : *this->players_online) {
        if (!player.second) this->player_votes.insert({player.first,VOTE_NO});
        else this->player_votes.insert({player.first,NO_VOTE_YET});
    }
}

LevelManager::LevelManager(Model *model,std::map<std::string,bool>* 
  players_online) : map_parser(model) {
    this->model = model;
    this->actual_level = 0;
    this->json_files.push_back(LEVEL_1);
    this->json_files.push_back(LEVEL_2);
    this->players_online = players_online;
}

void LevelManager::managePlayerVote(std::string &player,int vote) {
    if (vote == VOTE_NO) this->player_votes[player] = VOTE_NO;
    if (vote == VOTE_YES) this->player_votes[player] = VOTE_YES;
}

void LevelManager::restartModel() {
    this->model->resetModel();
}

void LevelManager::restartGameLoop() {
    this->model->resetGameLoop();
}

void LevelManager::loadLevel() {
    std::list<Object*> objects = this->map_parser.addObjectsToModel
      (this->json_files.at(this->actual_level));
    this->actual_level++;
    for (auto i = objects.begin(); i != objects.end();) {
        (*i)->aggregate();
        delete (*i);
        i = objects.erase(i);
    }
    this->model->addButtonsToDoors();
}

void LevelManager::loadNextLevel() {
    if (this->allLevelPlayed()) return;
    this->restartModel();
    this->loadLevel();
    this->setVotes();
    this->restartGameLoop();
}

int LevelManager::playersAcceptNextLevel() {
    for (auto player : this->player_votes) {
        if (!player.second) return WAITING;
        if (player.second == VOTE_NO) return NO_PLAY_NEXT_LEVEL;
    }
    return PLAY_NEXT_LEVEL;
}

void LevelManager::getCustomLevel() {

}

void LevelManager::loadFirstLevel() {
   this->loadLevel();
}

bool LevelManager::allLevelPlayed() {
    return (this->actual_level == this->json_files.size());
}
