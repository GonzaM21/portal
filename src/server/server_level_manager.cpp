#include "server_level_manager.h"
#define LEVEL_1 "json_file"
#define LEVEL_2 "json_file2"
#define FINISH_GAME 2

void LevelManager::setVotes() {
    for (auto it = this->player_votes.cbegin(); it != this->player_votes.cend();) {
      it = this->player_votes.erase(it); 
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

void LevelManager::managePlayerVote(int vote) {
    if (vote == VOTE_YES) {
        this->player_votes.push_back(VOTE_YES);
        return;
    }
    this->model->setNextScene();
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
    this->setVotes();
}

void LevelManager::addPlayersToNewLevel() {
    for (auto player : *this->players_online) {
        std::string player_name = player.first;
        this->model->addPlayer(player_name);
    }
}

void LevelManager::loadNextLevel() {
    if (this->allLevelPlayed()) return;
    this->model->resetModel();
    this->addPlayersToNewLevel();
    this->loadLevel();
    this->setVotes();
    this->restartGameLoop();
}

int LevelManager::playersAcceptNextLevel() {
    return (this->player_votes.size()==(*this->players_online).size());
}

void LevelManager::loadFirstLevel() {
   this->loadLevel();
}

bool LevelManager::allLevelPlayed() {
    return (this->actual_level == this->json_files.size());
}

int LevelManager::getNumberOfLevels() {
    return this->json_files.size();
}