#include <iostream>
#include "server_command_mates.h"


CommandMates :: CommandMates(Model *model) {
    this->model = model;
}

void CommandMates :: execute() {
    this->model->sendInfoPlayers();
}
