#include "../server/server_command_factory.h"

CommandFactory :: CommandFactory(Model *model,MapParser *map_parser,
    std::map<std::string,bool>* players_connection) {
    this->model = model;
    this->map_parser = map_parser;
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