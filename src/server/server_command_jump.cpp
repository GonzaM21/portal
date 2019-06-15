#include "server_command_jump.h"

CommandJump :: CommandJump(Model *model,std::string &player) {
    this->model = model;
    this->player = player;
}

void CommandJump :: execute() {
    this->model->makePlayerJump(player);
}
