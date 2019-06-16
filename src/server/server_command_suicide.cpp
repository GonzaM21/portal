#include "server_command_suicide.h"

CommandSuicide :: CommandSuicide(Model *model,std::string &player) {
    this->model = model;
    this->player = player;
}

void CommandSuicide :: execute() {
    this->model->killPlayer(this->player);
}
