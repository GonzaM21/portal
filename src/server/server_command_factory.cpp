#include "../server/server_command_factory.h"

CommandFactory :: CommandFactory(Model *model,MapParser *map_parser) {
    this->model = model;
    this->map_parser = map_parser;
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