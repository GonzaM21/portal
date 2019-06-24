#include "server_command_factory.h"

CommandFactory :: CommandFactory(Model *model,LevelManager *level_manager,
    std::map<std::string,bool>* players_connection) {
    this->model = model;
    this->level_manager = level_manager;
    this->players_connection = players_connection;
}

CommandMates* CommandFactory :: createCommandMates() {
    return new CommandMates(this->model);
}

CommandJoin* CommandFactory :: createCommandJoin(std::string &player) {
    return new CommandJoin(this->model,player);
}

CommandStart* CommandFactory :: createCommandStart() {
    return new CommandStart(this->model);
}

CommandJump* CommandFactory :: createCommandJump(std::string &player) {
    return new CommandJump(this->model,player);
}

CommandMove* CommandFactory :: createCommandMove(std::string &player,char &direction) {
    return new CommandMove(this->model,player,direction);
}

CommandShoot* CommandFactory :: createCommandShoot(std::string &player,
  std::string &x_destiny,std::string &y_destiny,std::string &portal_num) {
    return new CommandShoot(this->model,player,x_destiny,y_destiny,portal_num);
}

CommandMoveRock* CommandFactory :: createCommandMoveRock(std::string &player) {
    return new CommandMoveRock(this->model,player);
}

CommandDisconnected* CommandFactory ::createCommandDisconnected(std::string &player) {
    return new CommandDisconnected(this->players_connection,player);
}

CommandKill* CommandFactory::createCommandKill(std::string &voter) {
    return new CommandKill(this->model,voter);
}

CommandSuicide* CommandFactory::createCommandSuicide(std::string &player) {
    return new CommandSuicide(this->model,player);
}

CommandInmortal* CommandFactory::createCommandInmortal(std::string &player) {
    return new CommandInmortal(this->model, player);
} 

CommandAntiGravity* CommandFactory::createCommandAntiGravity(std::string &player) {
    return new CommandAntiGravity(this->model, player);
}

CommandFinishGame* CommandFactory::createCommandEndGame() {
    return new CommandFinishGame(this->model);
}

CommandNextLevel* CommandFactory::createCommandNextLevel(std::string &player) {
    return new CommandNextLevel(this->model,this->level_manager,player);
}