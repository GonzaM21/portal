#include "server_command_anti_gravity.h"

CommandAntiGravity :: CommandAntiGravity(Model *model,std::string &player) {
    this->model = model;
    this->player = player;
}

void CommandAntiGravity :: execute() {
    this->model->makePlayerAntiGravity(player);
}
