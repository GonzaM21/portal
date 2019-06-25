#include "server_command_move.h"

CommandMove :: CommandMove(Model *model,std::string &player,char &direction) {
    this->model = model;
    this->player = player;
    this->direction = direction;
}

void CommandMove :: execute() {
    this->model->makePlayerMove(this->player,this->direction);
}