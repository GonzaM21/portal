#include "server_command_inmortal.h"

CommandInmortal ::CommandInmortal(Model *model,std::string &player) {
    this->model = model;
    this->player = player;
}

void CommandInmortal :: execute() {
    this->model->makePlayerInmortal(player);
}
