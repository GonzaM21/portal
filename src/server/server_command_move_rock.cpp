#include "server_command_move_rock.h"

CommandMoveRock :: CommandMoveRock(Model *model,std::string &player) {
    this->model = model;
    this->player = player;
}

void CommandMoveRock :: execute() {
    this->model->makePlayerMoveRock(player);
}
