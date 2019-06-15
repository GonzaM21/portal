#include "server_command_join.h"

CommandJoin :: CommandJoin(Model *model,std::string &player) {
    this->model = model;
    this->player = player;
}

void CommandJoin :: execute() {
    this->model->addPlayer(this->player);
}
