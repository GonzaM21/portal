#include "server_command_kill.h"

CommandKill :: CommandKill(Model *model,std::string &voter) {
    this->model = model;
    this->player = player;
    this->voter = voter;
}

void CommandKill :: execute() {
    this->model->voteToKill(player);
}
